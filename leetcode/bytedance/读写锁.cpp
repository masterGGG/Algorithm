#include <iostream> 
#include <pthread>
#include <sched.h>
#include <errno.h>

using namespace std;

template<typename T, typename F>
static inline T inc(T &src, F delta) {
    return __sync_add_and_fetch(src, delta);
}

struct spin_rwlock_t {
    int cnt;    //剩余可上锁的次数
    int wait;   //是否正在上写锁
    int type;   //
};

const int MAX_LOCK = 10000;

void spin_rwlock_init(struct spin_rwlock_t *lock) {
    lock->cnt = MAX_LOCK;
    lock->wait = 0;
    lock->type = 0;
}

int spin_rwlock_rlock(struct spin_rwlock_t *lock) {
    while (lock->wait) {
        sched_yield();
    }

    while (inc(lock->cnt, -1) < 0) {
        inc(lock->cnt, 1);
        sched_yield();
    }

    lock->type = 0;

    return 0;
}

int spin_rwlock_tryrlock(struct spin_rwlock_t *lock) {
    if (inc(lock->cnt, -1) < 0) {
        inc(lock->cnt, 1);
        return EBUSY;
    }

    lock->type = 0;
    return 0;
}

int spin_rwlock_wlock(struct spin_rwlock_t *lock) {
    bool wait = false;

    while (inc(lock->cnt, -MAX_LOCK) < 0) {
        if (!wait) {
            inc(lock->wait, 1);
            wait = true;
        }

        inc(lock->cnt, MAX_LOCK);
        sched_yield();
    }

    if (wait) {
        inc(lock->wait, -1);
    }

    lock->type = 1;

    return 0;
}

int spin_rwlock_trywlock(struct spin_rwlock_t *lock) {
    if (inc(lock->cnt, -MAX_LOCK) < 0) {
        inc(lock->cnt, MAX_LOCK);
        return EBUSY;
    }

    lock->type = 1;
    return 0;
}

void spin_rwlock_unlock(struct spin_rwlock_t *lock) {
    inc(lock->cnt, lock->type ?  MAX_LOCK : 1);
}

int main() {
    return 0;
}

#include <iostream>
#include <atomic>         // std::atomic
#include <thread>         // std::thread, std::this_thread::yield
#include <mutex>
#include <condition_variable>

static int LOCK_MAX = 10000;

class RWLock {
public:
    RWLock() : capacity(atomic<int>(LOCK_MAX)) {}

    int rlock() {
        unique_lock<mutex> rlock(rmtx);

        locker.unlock();
    }

    int wlock() {
        unique_lock<mutex> wlock(wmtx);

        while (capacity < LOCK_MAX) {
            cond.wait(wlock);
        }

        type.store(1, std::memory_order_relaxed);
        capacity.store(0, std::memory_order_relaxed);
        locker.unlock();
    }

    int unlock() {}
private:
    mutex               rmtx;
    mutex               rmtx;
    condition_variable  cond;
    atomic<int>         capacity;
    atomic<int>         type;
};
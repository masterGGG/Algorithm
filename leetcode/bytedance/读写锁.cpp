class RWLock {
public:
  RWLock() = default;
  ~RWLock() = default;
public:
  void rlock() {
    std::unique_lock<std::mutex> lock_(mutex_);
    rcond_.wait(lock_, [=]()->bool{
      return wcnt_ == 0;
    });
    rcnt++;
  }

  int try_rlock() {
    std::unique_lock<std::mutex> lock_(mutex_);
    rcond_.wait(lock_, [=]()->bool{
      return wcnt_ == 0;
    });
  }

  void wlock() {
    std::unique_lock<std::mutex> lock_(mutex_);
    wcnt_++;
    wcond_.wait(lock_, [=]()->bool {
      return rcnt_ == 0 && !writing_;
    });
    writing_ = true;
  }

  void unlock() {
    std::unique_lock<std::mutex> lock_(mutex_);
    if (writing_) {
      wcnt_--;
      if (wcnt == 0) {
        rcond_.notify_all();
      } else {
        wcond_.notify_one();
      }
      writing_ = false;
    } else {
      rcnt_--;

      if (!rcnt && wcnt_) {
        wcond_.notify_one();
      }
    }
  }
private:
  std::mutex mutex_;
  std::condition_variable rcond_;
  std::condition_variable wcond_;
  std::atomic<int> rcnt{0};
  std::atomic<int> wcnt{0};
  bool writing_{false};
};
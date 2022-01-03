template <typename T>
class Singleton {
  typename shared_ptr<T> PTR;
private:
  Singleton() {}
  static PTR instance_;
  static std::mutex mutex_;

public:
  Singleton& operator=(const Singleton &);
  Singleton(Singleton &);

  template <typename Args>
  static PTR getInstance(Args&&... args) {
    if (instance_ == nullptr) {
      std::lock_guard<std::mutex> lock(mutex_);

      if (instance_ == nullptr) {
        instance_ = std::make_shared<T>(std::forward<Args>(args)...);
      }
    }

    return instance_;
  }
};

//volatile

/*
c++11另一个重要的细节改动，那就是多线程情况下，局部static变量的初始化是线程安全的，语言确保局部静态变量只会初始化一
*/
template<typename T>
class XX_Singleton {
public:
  static T* getInstance() {
    static T _instance;
    return &_instance;
  }
};

/*
原子变量synchronize-with关系
*/
template<typename T>
class Singleton {
private:
  static std::atomic<T*> _pInstance;
  static std::mutex _mutex;
  Singleton() {};
  Singleton(Singleton &);
  Singleton& operator=(const Singleton&);
public:
  virtual ~Singleton() {}
  static T* getInstance() {
    T* tmp = _pInstance.load(memory_order_acquire);
    if(tmp == nullptr) {
      std::lock_guard<mutex> lock(_mutex);
      tmp = _pInstance.load(memory_order_relaxed);
      if(tmp == nullptr) {
          tmp = new T;
          _pInstance.store(tmp, memory_order_release);
      }
    }
    return tmp;
  }
};
template <typename T>
class Singleton {
  typename shared_ptr<T> PTR;
private:
  Singleton() {}
  static PTR instance_;
  static std::mutex mutex_;

public:
  Singleton(void) =delete;
  Singleton(Singleton &) = delete;

  static PTR getInstance() {
    if (instance_ == nullptr) {
      std::lock_guard<std::mutex> lock(mutex_);

      if (instance_ == nullptr) {
        instance_ = std::shared_ptr<T>(new T);
      }
    }

    return instance_;
  }
};
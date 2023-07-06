#pragma once

#include <utility>
#include <cstddef>

/*
template <typename T>
void construct(void* mem_ptr, T&& obj) {
  
}
*/

template <typename T, typename... Args>
void construct(void* mem_ptr, Args&&... args) {
  ::new(mem_ptr) T(std::forward<Args...>(args...));
}

template <typename T>
void destruct(T& obj) {
  obj->~T();
}

template <class T>
class VectorStorage {
 public:
  VectorStorage(size_t capacity) :
    data(static_cast<T*>(new std::byte[capacity * sizeof(T)])),
    capacity(capacity) {}; 

 protected:
  T* data;
  size_t capacity;
  size_t size = 0;

/*
  DynamicMemory(size_t count) : capacity_(count) {
      storage_ = new uint8_t[capacity_ * sizeof(T)];
      data_ = reinterpret_cast<T*>(storage_);
      
      for (size_t i = 0; i < count; ++i) {
          new(data_ + i) T();
      }
  }

  DynamicMemory(size_t count, const T& val) : capacity_(count) {
      storage_ = new uint8_t[capacity_ * sizeof(T)];
      data_ = reinterpret_cast<T*>(storage_);
    
      for (size_t i = 0; i < count; ++i) {
          new(data_ + i) T(val);
      }
  }
  ~DynamicMemory() {
      delete[] storage_;
  }

  protected:

    size_t capacity() const {
        return capacity_;
    }

    T& operator [](int idx) {
        assert(idx >= 0 && idx <= capacity_);
        return data_[idx];
    }
    const T& operator [](int idx) const {
        assert(idx >= 0 && idx <= capacity_);
        return data_[idx];
    }

    void insert(size_t idx, const T& val) {
        new(data_ + idx) T(val);
    }

    void insert(size_t idx, T&& val) {
        new(data_+ idx) T(std::move(val));
    }

    void storageRealloc() {
        reallocate();
    }
    
    /*
    void reallocate() {
      size_t old_capacity_ = capacity_;
      capacity_ *= 2;

      uint8_t* new_storage = new uint8_t[capacity_ * sizeof(T)];
      T* new_data = reinterpret_cast<T*>(new_storage);

      for (size_t i = 0; i < old_capacity_; ++i) {
        new(new_data + i) T(std::move(data_[i]));
      }

      data_ = new_data;
      delete[] storage_;
      storage_ = new_storage;
    };
    */
};
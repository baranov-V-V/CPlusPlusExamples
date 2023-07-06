#pragma once

#include "vector_storage.hpp"

template <class T>
class Vector : public VectorStorage<T> {
 public:
  Vector() : VectorStorage<T>(10) {
    std::cout << "vector ctor" << std::endl;
  };

  Vector(size_t capacity) : VectorStorage<T>(capacity) {
    std::cout << "vector ctor" << std::endl;
  };
  
 private:
};
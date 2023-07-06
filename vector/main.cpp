#include <iostream>
#include <exception>
#include <vector>

#include "vector.hpp"

class ThrowingCopyClass {
 public:
  ThrowingCopyClass() {
    std::cout << "ThrowingCopyClass ctor" << std::endl;
  };
  ~ThrowingCopyClass() {
    std::cout << "ThrowingCopyClass dtor" << std::endl;
  }
  ThrowingCopyClass(const ThrowingCopyClass&) {
    throw_counter++;
    if (throw_counter == need_to_throw_num) {
      throw std::runtime_error("exception");
    }
  }
  ThrowingCopyClass(ThrowingCopyClass&&) noexcept = default;

 private:
  static int throw_counter;
  static int need_to_throw_num;
};

int ThrowingCopyClass::need_to_throw_num = 5;
int ThrowingCopyClass::throw_counter = 0;

int main(int argc, char const *argv[]) {
  Vector<ThrowingCopyClass> v{};  

  return 0;
}

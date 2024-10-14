#include "class.h"
#include <iostream>

// 默认构造函数
template <typename T>
MyClass<T>::MyClass() : attribute(std::make_unique<T>(T())) {
  std::cout << "默认构造函数调用" << std::endl;
}

// 自定义构造函数，使用初始化列表
template <typename T>
MyClass<T>::MyClass(T a) : attribute(std::make_unique<T>(a)) {
  std::cout << "自定义构造函数调用" << std::endl;
}

// 拷贝构造函数，实现深拷贝
template <typename T>
MyClass<T>::MyClass(const MyClass &other) : attribute(std::make_unique<T>(*other.attribute)) {
  std::cout << "拷贝构造函数调用" << std::endl;
}

// 移动构造函数
template <typename T>
MyClass<T>::MyClass(MyClass &&other) noexcept : attribute(std::move(other.attribute)) {
  std::cout << "移动构造函数调用" << std::endl;
}

// 赋值运算符重载，实现深拷贝
template <typename T>
MyClass<T> &MyClass<T>::operator=(const MyClass &other) {
  if (this == &other)
    return *this;  // 自我赋值检查
  attribute = std::make_unique<T>(*other.attribute);  // 深拷贝
  std::cout << "赋值运算符重载调用" << std::endl;
  return *this;
}

// 移动赋值运算符重载
template <typename T>
MyClass<T> &MyClass<T>::operator=(MyClass &&other) noexcept {
  if (this == &other)
    return *this;  // 自我赋值检查
  attribute = std::move(other.attribute);  // 移动指针
  std::cout << "移动赋值运算符重载调用" << std::endl;
  return *this;
}

// getter 函数，用于获取 attribute 的值
template <typename T>
T MyClass<T>::getValue() const {
  return *attribute;
}

// setter 函数，用于设置 attribute 的值
template <typename T>
void MyClass<T>::setValue(T value) {
  *attribute = value;
}

// 析构函数
template <typename T>
MyClass<T>::~MyClass() {
  std::cout << "析构函数调用" << std::endl;
}

#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <memory>  // 用于智能指针
#include <string>

// 模板类 MyClass，支持不同类型的属性
template <typename T> 
class MyClass {
private:
  std::unique_ptr<T> attribute;  // 使用智能指针来管理属性

public:
  // 默认构造函数
  MyClass();

  // 自定义构造函数，使用初始化列表
  MyClass(T a);

  // 拷贝构造函数，支持深拷贝
  MyClass(const MyClass &other);

  // 移动构造函数，提高效率
  MyClass(MyClass &&other) noexcept;

  // 赋值运算符重载，支持深拷贝
  MyClass &operator=(const MyClass &other);

  // 移动赋值运算符重载
  MyClass &operator=(MyClass &&other) noexcept;

  // getter 函数，用于获取 attribute 的值
  T getValue() const;

  // setter 函数，用于设置 attribute 的值
  void setValue(T value);

  // 友元函数，用于输出 MyClass 对象的值
  friend std::ostream &operator<<(std::ostream &out, const MyClass &obj) {
    if (obj.attribute) {
      out << *(obj.attribute);
    } else {
      out << "null";
    }
    return out;
  }

  // 析构函数
  ~MyClass();
};

#endif

// Blank header file
#ifndef CLASS_H
#define CLASS_H
#include <string>
template <typename T> class MyClass {
private:
  T attribute;

public:
  MyClass();
  MyClass(T a);
  T  getValue ()const;
  void setValue(T value);

  ~MyClass();
};
// #include "class.cpp"
#endif
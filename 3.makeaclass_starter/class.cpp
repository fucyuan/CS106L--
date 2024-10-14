// Blank cpp file
#include "class.h"
template <typename T> MyClass<T>::MyClass() : attribute(0){};
template <typename T> MyClass<T>::MyClass(T a) : attribute(a){};
template <typename T> T MyClass<T>::getValue() const { return attribute; }
template <typename T> void MyClass<T>::setValue(T value) { attribute = value; }
template<typename T> MyClass<T>::~MyClass(){};
template class MyClass<int>;
template class MyClass<std::string>;
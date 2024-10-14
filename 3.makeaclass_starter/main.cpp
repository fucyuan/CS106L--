#include "class.h"
#include "class.cpp"
#include <iostream>
#include <string>
/*
 * 作业 3: 创建一个类！
 * 要求：
 * 必须有一个自定义构造函数 ❌
 * 必须有一个默认构造函数 ❌
    - 即构造函数重载
 * 必须有私有成员（函数和/或变量）❌
 * 必须有公有成员（函数）❌
 * 必须有至少一个 getter 函数 ❌
 * 必须有至少一个 setter 函数 ❌
 */

int main() {
  // 初始化类并运行此文件
  MyClass<int> classOne;  // 使用默认构造函数初始化
  MyClass<std::string> classTwo("hello");  // 使用自定义构造函数初始化
  MyClass<std::string> classTwo2;
  classTwo2=std::move(classTwo);
  std::cout << classOne.getValue() << std::endl;  // 输出 classOne 的值
  std::cout << classTwo2.getValue() << std::endl;  // 输出 classTwo 的值
  return 0;
}

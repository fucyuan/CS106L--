#include "class.h"
#include "class.cpp"
#include <iostream>
#include <string>
/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */

int main() {
  // initialize class and run this file
  MyClass<int> classOne;
  MyClass<std::string> classTwo("hello");
  std::cout << classOne.getValue() << std::endl;
  std::cout << classTwo.getValue() << std::endl;
  return 0;
}
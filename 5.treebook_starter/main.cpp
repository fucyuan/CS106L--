#include "user.h"  // 包含用户类的头文件
#include <iostream> // 用于标准输入输出


// 打印指定用户的好友列表
void printFriends(const User &user) {
  std::cout << user.getName() << " is friends with: " << std::endl;  // 输出当前用户的姓名
  // 遍历用户的好友列表，逐个输出好友姓名
  for (auto &user : user.getFriends()) {
    std::cout << "  " << user.getName() << std::endl;  // 输出好友的姓名
  }
}

int main() {
  // 创建一组用户对象
  User alice("Alice");
  User bob("Bob");
  User charlie("Charlie");
  User dave("Dave");

  // 使他们成为朋友
  alice = alice + bob;  // Alice 和 Bob 成为朋友
  alice = alice + charlie;  // Alice 和 Charlie 成为朋友

  dave = dave + bob;  // Dave 和 Bob 成为朋友
  charlie = charlie + dave;  // Charlie 和 Dave 成为朋友

  // 输出每个用户的好友列表
  printFriends(alice);  // 输出 Alice 的好友
  printFriends(bob);  // 输出 Bob 的好友
  printFriends(charlie);  // 输出 Charlie 的好友
  printFriends(dave);  // 输出 Dave 的好友

  return 0;
}

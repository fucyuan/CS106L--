#include "user.h"
#include <iostream>
#include <utility> // 为 std::move 提供支持

// 默认构造函数
User::User() : name("") {}

// 自定义构造函数
User::User(std::string name) : name(name) {}

// 拷贝构造函数
User::User(const User &other) : name(other.name), friends(other.friends) {}

// 拷贝赋值运算符
User &User::operator=(const User &other) {
    if (this == &other)
        return *this;
    name = other.name;
    friends = other.friends;
    return *this;
}

// 移动构造函数
User::User(User &&other) : name(std::move(other.name)), friends(std::move(other.friends)) {}

// 移动赋值运算符
User &User::operator=(User &&other) {
    if (this != &other) {
        name = std::move(other.name);
        friends = std::move(other.friends);
    }
    return *this;
}

// 获取用户名
std::string User::getName() const {
    return name;
}

// 获取好友列表
std::set<User> User::getFriends() const {
    return friends;
}

// 设置用户名
void User::setName(std::string name) {
    this->name = name;
}

// 重载 < 运算符，用于 set 中排序
bool User::operator<(const User &other) const {
    return name < other.name;
}

// 重载 + 运算符，允许用户之间成为朋友
User &&operator+(User &me, User &other) {
    // 将双方互相添加为朋友
    if (!me.getFriends().count(other)) {
        me.friends.insert(other);
    }
    if (!other.getFriends().count(me)) {
        other.friends.insert(me);
    }
    return std::move(me);
}

#ifndef USER_H
#define USER_H

#include <set>
#include <string>

class User {
public:
    // 默认构造函数
    User();

    // 自定义构造函数，接受用户名
    User(std::string name);

    // 拷贝构造函数
    User(const User &other);

    // 拷贝赋值运算符
    User &operator=(const User &other);

    // 移动构造函数
    User(User &&other);

    // 移动赋值运算符
    User &operator=(User &&other);

    // 获取用户名
    std::string getName() const;

    // 获取好友列表
    std::set<User> getFriends() const;

    // 设置用户名
    void setName(std::string name);

    // 重载小于运算符，用于在 set 中排序
    bool operator<(const User &other) const;

    // 声明 + 运算符为友元函数
    friend User &&operator+(User &me, User &other);

private:
    std::string name;
    std::set<User> friends;
};

#endif

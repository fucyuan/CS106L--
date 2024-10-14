# 作业: 用户好友关系管理系统

## 简介

本次作业要求实现一个简单的用户好友关系管理系统。每个用户都有一个唯一的名称，并且可以通过 `+` 运算符与其他用户成为朋友。好友关系是双向的，也就是说，如果用户 A 是用户 B 的朋友，那么用户 B 也是用户 A 的朋友。此外，用户好友列表存储在一个 `std::set` 容器中，用于自动管理好友的唯一性和排序。

---

## 项目文件结构

- **`user.h`**: 定义了 `User` 类的接口，包括用户的基本信息（姓名、好友列表）、构造函数、赋值运算符、以及友元函数 `operator+`。
- **`user.cpp`**: 实现了 `User` 类的成员函数，包括拷贝构造、移动构造、赋值运算符、好友关系的管理等功能。
- **`main.cpp`**: 主程序文件，测试 `User` 类的功能，包括用户创建、用户间的好友关系建立，以及输出用户的好友列表。
- **`README.md`**: 当前文档，解释项目的功能、文件结构、编译运行方法等。

---

## 类功能说明

### 类 `User`

#### 私有成员：
- **`std::string name`**: 存储用户的名称。
- **`std::set<User> friends`**: 存储用户的好友列表，使用 `std::set` 确保好友的唯一性，并根据名字排序。

#### 公有成员函数：
1. **构造函数**：
   - `User()`：默认构造函数，创建一个没有名字的用户。
   - `User(std::string name)`：接受一个名称，创建带有名字的用户。

2. **拷贝构造函数**：
   - 复制已有 `User` 对象，复制其名称和好友列表。

3. **移动构造函数**：
   - 使用右值引用，移动用户对象的名称和好友列表，避免不必要的拷贝。

4. **赋值运算符**：
   - 实现了拷贝赋值和移动赋值，确保用户对象可以通过赋值操作进行复制或移动。

5. **getter 和 setter**：
   - `std::string getName() const`：获取用户的名称。
   - `std::set<User> getFriends() const`：获取用户的好友列表。
   - `void setName(std::string name)`：设置用户的名称。

6. **运算符重载**：
   - `bool operator<(const User &other) const`：根据用户的名字实现比较，用于在 `std::set` 中对用户对象进行排序。
   - `friend User &&operator+(User &me, User &other)`：重载 `+` 运算符，表示两个用户通过 `+` 运算符互相成为朋友，并返回一个右值引用以支持链式操作。

---

## 编译与运行

### 编译
使用以下命令编译程序：
```bash
g++ -std=c++2a main.cpp user.cpp -o main
```

### 运行
编译完成后，使用以下命令运行程序：
```bash
./main
```

程序会输出每个用户的好友列表。

---

## 功能示例

### 输入（代码片段）：
```cpp
int main() {
    User alice("Alice");
    User bob("Bob");
    User charlie("Charlie");
    User dave("Dave");

    alice = alice + bob;
    alice = alice + charlie;

    dave = dave + bob;
    charlie = charlie + dave;

    printFriends(alice);
    printFriends(bob);
    printFriends(charlie);
    printFriends(dave);

    return 0;
}
```

### 输出：
```
Alice is friends with: 
  Bob
  Charlie
Bob is friends with: 
  Alice
  Dave
Charlie is friends with: 
  Alice
  Dave
Dave is friends with: 
  Bob
  Charlie
```

---

## 项目特点

1. **双向好友关系**：
   - `operator+` 运算符实现了双向好友关系，当用户 A 和用户 B 互为好友时，A 的好友列表中有 B，B 的好友列表中也有 A。

2. **链式调用**：
   - `operator+` 运算符返回 `User` 对象的右值引用，允许多个好友关系通过链式调用进行建立。例如：`alice = alice + bob + charlie;`。

3. **高效的好友管理**：
   - 通过 `std::set` 容器管理用户的好友列表，确保好友的唯一性，且在插入新好友时自动排序。

---

## 总结

本项目通过 C++ 的类设计、运算符重载、移动语义等概念，实现了一个用户好友管理系统。用户可以通过 `+` 运算符方便地与其他用户建立好友关系，并能够通过链式调用一次性建立多个好友关系。通过 `std::set` 容器确保了好友的唯一性和自动排序。

---
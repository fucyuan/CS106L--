#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <string>

std::string STUDENT_PATH = "students.txt";  // 学生名单文件路径

// 打印申请者名单
void print_applicants(std::set<std::string> applicants);

// 获取申请者名单，返回一个std::set集合
std::set<std::string> get_applicants(std::string filename) {
  // 打开文件
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    // 如果文件打开失败，输出错误信息
    std::cerr << "Failed to open file: " << filename << std::endl;
  }
  
  std::string name;
  std::set<std::string> applicants;  // 使用set存储学生姓名，避免重复
  // 逐行读取文件中的学生姓名
  while (std::getline(ifs, name)) {
    applicants.insert(name);  // 将学生姓名插入到set中
  }
  
  return applicants;  // 返回存储了所有学生姓名的set
}

// 查找匹配的学生，返回一个包含指针的队列
using SQ=std::queue<const std::string *, std::list<const std::string *>>;
SQ find_matches(std::set<std::string> &students) {
  SQ matches;  // 用队列存储指向匹配学生的指针
  
  // 遍历所有学生姓名
  for (auto &student : students) {
    std::stringstream ss(student);  // 将每个学生的姓名放入字符串流中进行处理
    std::string first, last;
    ss >> first >> last;  // 将姓名拆分为名字和姓氏
    
    // 匹配条件：名字的第一个字母是'A'且姓氏的第一个字母是'X'
    if (first[0] == 'J' && last[0] == 'H') {
      matches.push(&student);  // 如果匹配，加入到匹配队列中
    }
  }
  
  return matches;  // 返回匹配结果
}

// 打印所有申请者的姓名
void print_applicants(std::set<std::string> applicants) {
  for (auto it = applicants.begin(); it != applicants.end(); ++it) {
    std::cout << *it << std::endl;  // 输出每个申请者的姓名
  }
}

// 打印匹配的学生姓名
void print_matches(std::queue<const std::string *,std::list<const std::string *>> matches) {
  if (matches.empty()) {
    // 如果没有找到匹配的学生，输出提示信息
    std::cout << "NO STUDENT FOUND." << std::endl;
    return;
  }
  
  // 逐个输出匹配的学生姓名
  while (!matches.empty()) {
    std::cout << *matches.front() << std::endl;
    matches.pop();
  }
}

int main() {
  // 主函数入口，执行获取和匹配逻辑
  auto applicants = get_applicants(STUDENT_PATH);  // 获取申请者名单
  auto matches = find_matches(applicants);  // 查找匹配的学生

  // 打印匹配的结果
  print_matches(matches);
  
  return 0;
}

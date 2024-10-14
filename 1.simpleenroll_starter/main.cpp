/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 */

#include "utils.cpp" // 包含实用程序头文件
#include <exception> // 包含异常处理库
#include <iostream>  // 包含输入输出流库
#include <system_error> // 包含系统错误处理库
#include <vector>    // 包含向量容器库

std::string COURSES_PATH = "courses.csv"; // 课程数据文件路径

// 用于测试 Course 结构体的函数
bool structTest() {
  Course c{"Standard C++ Programming", "1", "2023-2024 Winter"}; // 创建一个 Course 结构体实例
  return true;
}

int main() {
  std::vector<Course> vector_of_courses; // 创建一个存储 Course 结构体的向量

  if (!structTest()) { // 运行结构体测试
    std::cerr << "structTest Failed 😞"; // 测试失败输出错误信息
  } else {
    std::cout << "structTest Passed! ✅" << '\n'; // 测试通过输出成功信息
  }

  parse_csv(COURSES_PATH, vector_of_courses); // 解析 CSV 文件并填充向量

  write_courses_offered(vector_of_courses); // 写入提供的课程信息

  write_courses_not_offered(vector_of_courses); // 写入不提供的课程信息

  FILE *pipe = popen("python3 utils/autograder.py", "r"); // 调用外部 Python 脚本进行自动评分
  if (!pipe) // 检查管道是否成功打开
    return -1;

  char buffer[128]; // 定义缓冲区用于存储输出
  while (!feof(pipe)) { // 当未到达文件结束符
    if (fgets(buffer, 128, pipe) != NULL) // 从管道读取数据
      std::cout << buffer; // 输出读取的数据
  }
  pclose(pipe); // 关闭管道

  // 取消注释以下行进行调试
  // print_vector(vector_of_courses);
  return 0;
}

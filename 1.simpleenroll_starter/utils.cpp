/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 * Please complete each STUDENT TODO in this file.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

// (FIRST) STUDENT TODO: change how variables are passed into the functions you
// must complete

#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

// STUDENT TODO: add paths
std::string COURSES_OFFERED_CSV_PATH = "student_output/courses_offered.csv"; // 课程提供文件路径
std::string COURSES_NOT_OFFERED_CSV_PATH ="student_output/courses_not_offered.csv"; // 课程不提供文件路径

struct Course {
  std::string title; // 课程标题
  std::string number_of_units; // 学分数量
  std::string quarter; // 学季

  // 忽略此函数
  bool operator==(const Course &other) const {
    return title == other.title && number_of_units == other.number_of_units &&
           quarter == other.quarter;
  }
};

// 函数前向声明
void delete_elem_from_vector(std::vector<Course> &v, Course &elem);
std::vector<std::string> split(std::string s, char delim);

/*
 * 该函数应使用 Class 类型的结构体填充 vector_of_courses 向量
 * 我们希望使用 courses.csv 文件中的记录来创建这些结构体，其中每行是一个记录！
 *
 * 提示：
 * 1) 看看我们提供的 split 函数
 * 2) 每行都是一个记录！*这很重要，所以我们再说一遍 :>)*
 */
void parse_csv(std::string filename, std::vector<Course> &vector_of_courses) {
  // 学生 TODO: 实现此功能

  // 创建一个输入文件流对象 ifs，用于从指定文件中读取数据
  std::ifstream ifs(filename);

  // 检查文件是否成功打开
  if (!ifs.is_open()) {
    // 如果文件打开失败，输出错误信息并返回
    std::cerr << "无法打开文件: " << filename << std::endl;
  }

  // 创建一个字符串变量 line，用于存储文件中的每一行数据
  std::string line;

  // 读取文件的第一行数据，通常是标题行
  std::getline(ifs, line); // 跳过标题行

  // 使用一个 while 循环读取文件中的每一行数据，直到文件结束
  while (std::getline(ifs, line)) {
    // 将读取到的行数据按逗号分割，并将结果存储到一个字符串向量 raw_data 中
    std::vector<std::string> raw_data = split(line, ',');

    // 使用分割后的数据创建一个 Course 对象，并将其添加到 vector_of_courses 向量中
    vector_of_courses.emplace_back(Course{raw_data[0], raw_data[1], raw_data[2]});
  }
}


/*
 * 此函数有两个要求：
 * 1) 将提供的课程写入 student_output 文件夹中的 courses_offered.csv 文件
 * 2) 从 vector_of_courses 中删除提供的课程。
 * 重要：在写入文件后执行此操作！
 *
 * 提示：
 * 1) 记录需要删除的课程！
 * 2) 使用我们提供的 delete_elem_from_vector 函数！
 */
void write_courses_offered(std::vector<Course> &vector_of_courses) {
  // 学生 TODO: 实现此功能
  std::ofstream ofs(COURSES_OFFERED_CSV_PATH);
  std::vector<Course> to_be_deleted;
  if (ofs.is_open()) {
    for (auto &course : vector_of_courses) {
      if (course.quarter != "null") {
        ofs << course.title << "," << course.number_of_units << "," << course.quarter << std::endl;
        to_be_deleted.push_back(course);
      }
    }
  }
  ofs.close();
  for (auto &course : to_be_deleted) {
    delete_elem_from_vector(vector_of_courses, course);
  }
}

/*
 * 此函数将未提供的课程写入 student_output 文件夹中的 courses_not_offered.csv 文件
 *
 * 此函数始终在 write_courses_offered 函数之后调用。
 * vector_of_courses 将显然只包含未提供的课程，因为你在 write_courses_offered 函数中删除了提供的课程。
 *
 * 提示：这应与 write_courses_offered 非常相似
 */
void write_courses_not_offered(std::vector<Course> &vector_of_courses) {
  // 学生 TODO: 实现此功能
  std::ofstream ofs(COURSES_NOT_OFFERED_CSV_PATH);
  if (ofs.is_open()) {
    for (const auto &course : vector_of_courses) {
      ofs << course.title << "," << course.number_of_units << "," << course.quarter << std::endl;
    }
  }
  ofs.close();
}

/* ######## HEYA! DON'T MODIFY ANYTHING BEYOND THIS POINT THX ######## */

// TODO: 添加文档注释
void print_vector(std::vector<Course> vector_of_courses) {
  for (int i = 1; i < vector_of_courses.size(); ++i) {
    std::cout << vector_of_courses[i].title << "," << vector_of_courses[i].number_of_units << "," << vector_of_courses[i].quarter << std::endl;
  }
}

void delete_elem_from_vector(std::vector<Course> &v, Course &elem) {
  auto it = std::find(v.begin(), v.end(), elem);
  v.erase(it);
}

std::vector<std::string> split(std::string s, char delim) {
  std::vector<std::string> return_vec;
  std::stringstream ss(s);
  std::string token;
  while (getline(ss, token, delim)) {
    return_vec.push_back(token);
  }
  return return_vec;
}

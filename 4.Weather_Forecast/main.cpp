/*
Assignment 4: Weather Forecast

这个作业使用模板函数和lambda表达式来实现一个天气预报的程序。程序读取一组温度读数，
将华氏温度转换为摄氏温度，并计算每一天的最高、最低、平均温度。

*/

#include <algorithm>  // 包含STL算法库，用于使用 std::transform, std::max_element 等算法
#include <fstream>    // 文件流操作，用于文件读写
#include <iomanip>    // 控制输出格式，用于设置浮点数精度
#include <ios>        // 输入输出流的基本库
#include <iostream>   // 标准输入输出流，用于控制台输入输出
#include <iterator>   // 迭代器相关操作
#include <numeric>    // 用于数值计算，如 std::accumulate
#include <vector>     // 包含标准模板库中的动态数组容器 std::vector

// 模板函数 convert_f_to_c
// 将华氏温度转换为摄氏温度，返回类型始终为 double
template <typename Type> 
double convert_f_to_c(Type &&Fahrenheit) {
  return (Fahrenheit - 32) * 5.0 / 9;  // 转换公式：摄氏 = (华氏 - 32) * 5/9
}

// 模板函数 get_forecast
// 该函数接受一个容器 readings 和一个函数对象 fn，
// 使用函数对象 fn 计算每一天的某个统计值（如最大值、最小值或平均值）
// 并将结果存储在一个 vector 中返回
template <typename Container, typename Function>
std::vector<double> get_forecast(Container &readings, Function fn) {
  std::vector<double> result;  // 用于存储计算结果
  for (auto &reading : readings) {
    // 对每个子容器（即每一天的温度）应用函数 fn 并保存结果
    auto daily_result = fn(reading.begin(), reading.end());
    result.push_back(daily_result);  // 将结果存储到结果容器中
  }
  return result;  // 返回计算结果
}

// 测试函数 test_convert_f_to_c
// 将温度从华氏转换为摄氏，并输出到文件中
void test_convert_f_to_c(std::vector<std::vector<int>> readings) {
  std::ofstream ofs("output.txt");  // 打开输出文件流
  for (auto &reading : readings) {
    for (auto &temp : reading) {
      // 直接将转换后的摄氏温度写入文件
      ofs << convert_f_to_c(temp) << " ";
    }
    ofs << std::endl;  // 每一行结束后换行
  }
}

int main() {
  // 读取的华氏温度数据（每行代表一天的温度数据）
  std::vector<std::vector<int>> readings = {
      {70, 75, 80, 85, 90}, {60, 65, 70, 75, 80}, {50, 55, 60, 65, 70},
      {40, 45, 50, 55, 60}, {30, 35, 40, 45, 50}, {50, 55, 61, 65, 70},
      {40, 45, 50, 55, 60}};

  // 将华氏温度转换为摄氏温度并输出到 output.txt 文件
  std::vector<std::vector<double>> converted_readings(readings.size());  // 存储转换后的温度数据
  std::ofstream ofs("output.txt");  // 打开输出文件
  for (int i = 0; i < readings.size(); ++i) {
    converted_readings[i].resize(readings[i].size());  // 调整每一行大小
    // 使用 std::transform 将 readings[i] 中的温度转换为摄氏
    std::transform(readings[i].begin(), readings[i].end(),
                   converted_readings[i].begin(),
                   [](int f) { return convert_f_to_c(f); });  // lambda 表达式用于调用转换函数
  }
  
  // 设置输出精度为 2 位小数
  ofs << std::fixed << std::setprecision(4);
  // 将转换后的摄氏温度写入文件
  for (const auto readings : converted_readings) {
    for (auto temp : readings) {
      ofs << temp << "----";  // 输出每个温度
    }
    ofs << std::endl;  // 每一行结束后换行
  }

  // 计算每一天的最高温度并输出到 output.txt 文件
  ofs << "max: " << std::endl;  // 标题 "max"
  std::vector<double> max_results =
      get_forecast(converted_readings, [](auto begin, auto end) {
        return *std::max_element(begin, end);  // 使用 std::max_element 找到范围内的最大值
      });
  for (auto result : max_results) {
    ofs << result << " ";  // 输出每一天的最大温度
  }
  ofs << std::endl;

  // 计算每一天的最低温度并输出到 output.txt 文件
  ofs << "min: " << std::endl;  // 标题 "min"
  std::vector<double> min_results =
      get_forecast(converted_readings, [](auto begin, auto end) {
        return *std::min_element(begin, end);  // 使用 std::min_element 找到范围内的最小值
      });
  for (auto result : min_results) {
    ofs << result << " ";  // 输出每一天的最小温度
  }
  ofs << std::endl;

  // 计算每一天的平均温度并输出到 output.txt 文件
  ofs << "average: " << std::endl;  // 标题 "average"
  std::vector<double> average_results =
      get_forecast(converted_readings, [](auto begin, auto end) {
        return std::accumulate(begin, end, 0.0) / std::distance(begin, end);  // 使用 std::accumulate 计算范围内的总和并求平均值
      });
  for (auto result : average_results) {
    ofs << result << " ";  // 输出每一天的平均温度
  }
  return 0;
}

/*
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best
weather forecaster at the Stanford Daily. Be sure to read the assignment details
in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

// TODO: write convert_f_to_c function here. Remember it must be a template
// function that always returns a double. [function definition here]
//右值引用和模板函数实现完美转发
template <typename Type> double convert_f_to_c(Type &&Fahrenheit) {
  return (Fahrenheit - 32) * 5.0 / 9;
}

template <typename Container, typename Function>
std::vector<double> get_forecast(Container &readings, Function fn) {
  // TODO: write get_forecast here!
  std::vector<double> result;
  for (auto &reading : readings) {
    auto daily_result = fn(reading.begin(), reading.end());
    result.push_back(daily_result);
  }
  return result;
}

void test_convert_f_to_c(std::vector<std::vector<int>> readings) {
  // std::cout << convert_f_to_c(70) << std::endl;
  // std::cout << convert_f_to_c(58.3) << std::endl;
  std::ofstream ofs("output.txt");
  for (auto &reading : readings) {
    for (auto &temp : reading) {
      // 1、下面两行temp会先变为int
      //  temp = convert_f_to_c(temp);
      //  ofs << temp << " ";
      // 2、直接写入
      ofs << convert_f_to_c(temp) << " ";
    }
    ofs << std::endl;
  }
}

int main() {
  std::vector<std::vector<int>> readings = {
      {70, 75, 80, 85, 90}, {60, 65, 70, 75, 80}, {50, 55, 60, 65, 70},
      {40, 45, 50, 55, 60}, {30, 35, 40, 45, 50}, {50, 55, 61, 65, 70},
      {40, 45, 50, 55, 60}};

  // TODO: Convert temperatures to Celsius and output to output.txt
  // test_convert_f_to_c(readings);
  std::vector<std::vector<double>> converted_readings(readings.size());
  std::ofstream ofs("output.txt");
  for (int i = 0; i < readings.size(); ++i) {
    converted_readings[i].resize(readings[i].size());
    std::transform(readings[i].begin(), readings[i].end(),
                   converted_readings[i].begin(),
                   [](int f) { return convert_f_to_c(f); });
  }
  //写入文件
  ofs << std::fixed << std::setprecision(2);
  for (const auto readings : converted_readings) {
    for (auto temp : readings) {
      ofs << temp << " ";
    }
    ofs << std::endl;
  }

  // TODO: Find the maximum temperature for each day and output to output.txt
  ofs << "max: " << std::endl;
  std::vector<double> max_results =
      get_forecast(converted_readings, [](auto begin, auto end) {
        return *std::max_element(begin, end);
      });
  for (auto result : max_results) {
    ofs << result << " ";
  }
  ofs << std::endl;

  // TODO: Find the minimum temperature for each day and output to output.txt
  ofs << "min: " << std::endl;
  std::vector<double> min_results =
      get_forecast(converted_readings, [](auto begin, auto end) {
        return *std::min_element(begin, end);
      });
  for (auto result : min_results) {
    ofs << result << " ";
  }
  ofs << std::endl;

  // TODO: Find the average temperature for each day and output to output.txt
  ofs << "average: " << std::endl;
  std::vector<double> average_results =
      get_forecast(converted_readings, [](auto begin, auto end) {
        return std::accumulate(begin, end, 0.0) / std::distance(begin, end);
      });
  for (auto result : average_results) {
    ofs << result << " ";
  }
  return 0;
}
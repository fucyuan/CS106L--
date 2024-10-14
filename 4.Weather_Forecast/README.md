

# 作业 4: 天气预报程序

## 简介

本次作业要求通过使用 C++ 的模板函数、lambda 表达式和标准库算法，编写一个天气预报程序。程序会将一组温度读数从华氏度转换为摄氏度，并且计算每一天的最大温度、最小温度和平均温度，最后将结果输出到文件中。

---

## 要求

- **模板函数**：实现一个将华氏度转换为摄氏度的模板函数 `convert_f_to_c`。
- **lambda 表达式**：使用 lambda 表达式计算每一天的最大值、最小值和平均值。
- **标准库算法**：使用 `std::transform` 进行数据转换，使用 `std::max_element`、`std::min_element` 以及 `std::accumulate` 分别计算最大值、最小值和平均值。
- **输出文件**：将转换后的摄氏温度以及计算结果输出到 `output.txt` 文件。

---

## 文件结构

- `main.cpp`: 主程序文件，包含温度转换、统计计算及结果输出的逻辑。
- `README.md`: 当前文档，描述作业的内容和要求。
- `output.txt`: 程序运行后生成的文件，包含每一天的摄氏温度、最大值、最小值和平均值。

---

## 函数说明

### 1. **`convert_f_to_c`**
```cpp
template <typename Type> 
double convert_f_to_c(Type &&Fahrenheit);
```
- 将输入的华氏温度转换为摄氏温度，返回转换后的摄氏温度。
- 采用模板函数，使其能够处理不同类型的输入（如 `int` 或 `double`）。
- **转换公式**：摄氏温度 = `(华氏温度 - 32) * 5.0 / 9.0`。

### 2. **`get_forecast`**
```cpp
template <typename Container, typename Function>
std::vector<double> get_forecast(Container &readings, Function fn);
```
- 接收一个容器 `readings` 和一个函数 `fn`，对容器中的每一天温度数据应用 `fn` 函数，返回计算结果的向量。
- 通过 lambda 表达式调用 `std::max_element`、`std::min_element` 和 `std::accumulate` 来分别计算最大、最小和平均温度。

---

## 主要逻辑

### 1. 温度转换
程序使用 `std::transform` 将每一天的温度从华氏度转换为摄氏度，并将转换结果存储到 `converted_readings` 容器中：
```cpp
std::transform(readings[i].begin(), readings[i].end(),
               converted_readings[i].begin(),
               [](int f) { return convert_f_to_c(f); });
```

### 2. 计算最大值、最小值和平均值
使用 `get_forecast` 函数分别计算每一天的最大、最小和平均温度：
```cpp
// 计算最大值
std::vector<double> max_results = get_forecast(converted_readings, [](auto begin, auto end) {
    return *std::max_element(begin, end);
});

// 计算最小值
std::vector<double> min_results = get_forecast(converted_readings, [](auto begin, auto end) {
    return *std::min_element(begin, end);
});

// 计算平均值
std::vector<double> average_results = get_forecast(converted_readings, [](auto begin, auto end) {
    return std::accumulate(begin, end, 0.0) / std::distance(begin, end);
});
```

### 3. 输出到文件
计算结果通过 `std::ofstream` 输出到文件 `output.txt`，并使用 `std::fixed` 和 `std::setprecision(2)` 来设置输出精度为小数点后两位。

```cpp
ofs << std::fixed << std::setprecision(2);
```

每行温度数据和结果的输出格式为：
```
23.45 24.89 26.67 
max: 26.67
min: 23.45
average: 25.67
```

---

## 编译与运行

### 编译
使用以下命令编译程序：

```bash
g++ -o weather_forecast main.cpp
```

### 运行
编译成功后，使用以下命令运行程序：

```bash
./weather_forecast
```

程序将生成 `output.txt` 文件，其中包含每一天的摄氏温度数据及最大、最小、平均温度。

---

## 例子

### 输入（华氏温度数据）：
```cpp
std::vector<std::vector<int>> readings = {
    {70, 75, 80, 85, 90}, 
    {60, 65, 70, 75, 80}, 
    {50, 55, 60, 65, 70}, 
    {40, 45, 50, 55, 60}, 
    {30, 35, 40, 45, 50}
};
```

### 输出（`output.txt` 文件）：
```
21.11 23.89 26.67 29.44 32.22 
max: 32.22
min: 21.11
average: 26.67

15.56 18.33 21.11 23.89 26.67 
max: 26.67
min: 15.56
average: 21.11

10.00 12.78 15.56 18.33 21.11 
max: 21.11
min: 10.00
average: 15.56
...
```

---

## 总结

本次作业通过模板函数、lambda 表达式、标准库算法的结合，演示了如何有效地处理和转换温度数据，以及如何计算基本统计值（最大、最小、平均值）。通过这些工具，可以快速简洁地处理数据并将结果输出到文件，展示了 C++ 强大的标准库功能。


### 作业 1：SimpleEnroll

#### 截止日期：2024年4月19日星期五晚上11:59

#### 目录
- 概述
- 第0部分：阅读代码 + 类结构
- 第1部分：解析CSV
- 第2部分：写入开设的课程
- 第3部分：写入未开设的课程
- 恭喜你完成了！

### 概述

又到了使用SimpleEnroll的时间了🤗。每个斯坦福学生在某个时候都会意识到他们最终需要毕业，因此选课成为了一个战略性努力，以最大化毕业的学分，同时还能每天睡超过4个小时！

在这个希望是简短的作业中，我们将使用ExploreCourses API的数据，找出ExploreCourses上今年开设的CS课程以及未开设的课程！我们将利用流，同时练习C++中的初始化和引用。让我们开始吧ʕ•́ᴥ•̀ʔっ

你真的只需要关注两个文件：
- utils.cpp
- main.cpp

请点击这里下载起始代码，然后解压文件。

https://drive.google.com/file/d/1gJ6GI-s3Aj3_OeaoJV8eKN3OtC0GWxPi/view?usp=share_link

### 第0部分：阅读代码 + 添加路径 + 课程结构

1. 查看main.cpp文件中的main函数，特别注意vector_of_courses如何传递给parse_csv、write_courses_offered和write_courses_not_offered，这些函数在utils.cpp中定义。思考这些函数在做什么，你是否需要更改函数定义中的任何内容？提示：你需要。

2. 在utils/autograder.py文件中更改PATH
   - 首先在VSCode的终端中输入：pwd，从作业的主目录获取路径。你应该会得到类似如下的结果：
   - 然后将其复制并粘贴到PATH变量中，并用引号将其变成字符串。

3. 在utils.cpp文件中为Course结构体的字段编写正确的类型。记住流处理的是什么类型？

### 第1部分：解析CSV

查看courses.csv，这是一个包含三列的CSV文件：标题、学分数量和季度。实现parse_csv函数，以便对于CSV文件中的每一行，创建一个包含标题、学分数量和该行季度的Course结构体。

需要思考的几点：
1. 你将如何读取courses.csv？也许用流😏？
2. 你将如何获取文件中的每一行？

提示：
1. 利用我们提供的split函数获取一个如下所示的向量：[Title, Number of Units, Quarter]
   - 查看实现——对其进行推理，因为它使用了stringstream

### 第2部分：写入开设的课程

好了，现在你有一个填充好的vector_of_courses，其中包含所有courses.csv文件的记录，整齐地存储在一个Course结构体中！你只对开设的课程感兴趣，对吗？在这个函数中，写入所有没有“null”季度字段的课程到student_output/courses_offered.csv。

重要提示：写入文件时请遵循以下格式：
<Title>,<Number of Units>,<Quarter>

注意：逗号之间没有空格！如果不遵循此格式，自动评分器将不高兴！

此外，使用另一个向量跟踪开设的课程，并从vector_of_courses中删除它们。这意味着在这个函数运行后，vector_of_courses中应该只包含未开设的课程！为此，请查看提供的函数：delete_elem_from_vector！

不要担心，我知道你在想什么：

```cpp
auto it = std::find(v.begin(), v.end(), elem);
```

我们会在大约3周后告诉你这个。

### 第3部分：写入未开设的课程

所以你对未开设的课程感兴趣……在write_courses_not_offered函数中，将vector_of_courses中的课程写入student_output/courses_not_offered.csv。记住，由于你在第2部分中删除了开设的课程，因此vector_of_courses中显然只包含未开设的课程——幸运的你。因此，这一步应该看起来非常类似于第2部分，只是更短一些，简单一些。

### 编译说明！
要编译你编写的代码，请执行以下操作：

```bash
g++ -std=c++17 main.cpp -o main
```

要运行你编写的代码，现在可以执行（假设你遵循了上述步骤）：

```bash
./main
```

这将实际运行main函数，执行代码并运行自动评分器。如果你看到这个：

恭喜你完成了！🚀🚀🚀🚀

提交此作业的说明将在接近截止日期时发布在Ed上。

### 请在这里留下反馈！

### 特别鸣谢
特别感谢Jim Sproch提供ExploreCourses API。在尝试网页抓取ExploreCourses网站未成功后，Jim Sproch不仅提供了API，还回答了我们关于其使用的问题！

https://forms.gle/brWgfFKuhnCDp8LY7
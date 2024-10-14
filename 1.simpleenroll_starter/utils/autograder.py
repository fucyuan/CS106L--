'''
Hey friend! Glad you're curious about this, but please don't touch this file :>)
'''

from csv_utils import *  # 导入 csv_utils 模块中的所有内容
import os  # 导入 os 模块

def main():
    # fstream 写入测试！
    binary_to_csv("utils/courses_not_offered.bin", "utils/courses_not_offered.csv")  # 将二进制文件转换为 CSV 文件
    binary_to_csv("utils/courses_offered.bin", "utils/courses_offered.csv")  # 将二进制文件转换为 CSV 文件
    
    # 断言测试，确保生成的文件与预期文件相同
    assert files_are_equal("utils/courses_offered.csv", "student_output/courses_offered.csv"), "write_courses_offered test failed 😞"
    assert files_are_equal("utils/courses_not_offered.csv", "student_output/courses_not_offered.csv"), "write_courses_not_offered test failed 😞"
    
    # 删除临时生成的 CSV 文件
    os.remove("utils/courses_not_offered.csv")
    os.remove("utils/courses_offered.csv")
    
    print("Congratulations, your code passes all the autograder tests! ✅")

# 运行主函数
main()

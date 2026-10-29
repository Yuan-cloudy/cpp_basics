// 对应文档：docs/01-变量和输出.md
// 知识点：变量定义、初始化、基本数据类型、命名规则、std::cout 输出
// 编译：g++ -std=c++17 -Wall -Wextra -g 01_variables_and_output.cpp -o 01_variables_and_output.exe
//
// 说明：
// 1. 每个变量都必须先声明类型，再使用。
// 2. C++ 是大小写敏感的语言，age 和 Age 是两个不同的变量。
// 3. std::cout 是标准输出流，<< 用来把右侧的数据写入输出流。

#include <iostream>
#include <string>

int main() {
    // ---------- 1. 变量的声明与初始化 ----------
    int age;              // 只声明，未初始化，内部是未定义的值，不建议直接读取
    age = 18;             // 第一次赋值（初始化）

    int height = 175;     // 声明的同时初始化
    double weight = 65.5; // 双精度浮点数
    char gender = 'M';    // 字符使用单引号
    bool is_student = true;
    std::string name = "Xiao Ming"; // 字符串使用双引号

    // ---------- 2. 常用基本类型 ----------
    short small_number = 100;
    long long large_number = 1234567890123LL; // 64 位整数常量建议加 LL
    float score = 95.5f;                      // float 常量建议加 f
    unsigned int positive = 42;               // 无符号整数，不能表示负数

    // ---------- 3. 输出 ----------
    std::cout << "===== variables =====" << '\n';
    std::cout << "name: " << name << '\n';
    std::cout << "age: " << age << '\n';
    std::cout << "height: " << height << '\n';
    std::cout << "weight: " << weight << '\n';
    std::cout << "gender: " << gender << '\n';

    // std::boolalpha 让 bool 输出 true/false，而不是 1/0
    std::cout << std::boolalpha;
    std::cout << "is_student: " << is_student << '\n';

    std::cout << "small_number: " << small_number << '\n';
    std::cout << "large_number: " << large_number << '\n';
    std::cout << "score: " << score << '\n';
    std::cout << "positive: " << positive << '\n';

    // ---------- 4. 变量参与计算 ----------
    int a = 5;
    int b = 10;
    int sum = a + b;
    std::cout << "sum of " << a << " and " << b << " is " << sum << '\n';

    // std::endl 会输出换行并刷新缓冲区；'\n' 只换行，通常更轻量
    std::cout << "hello, C++!" << std::endl;

    return 0;
}

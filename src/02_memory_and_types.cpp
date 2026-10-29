// 对应文档：docs/02-数据存储区域和编码原理.md
// 知识点：进制与字节、ASCII、类型大小、类型转换、作用域、内存区域、编译过程
// 编译：g++ -std=c++17 -Wall -Wextra -g 02_memory_and_types.cpp -o 02_memory_and_types.exe

#include <cstdint>
#include <iostream>
#include <limits>

// 全局变量：存放在全局/静态区，程序运行期间一直存在
int global_number = 100;

int main() {
    // ---------- 1. 字节与类型大小 ----------
    // 1 字节（byte）= 8 位（bit）
    // sizeof 返回类型或对象占用的字节数，结果是 size_t 类型
    std::cout << "===== sizeof =====" << '\n';
    std::cout << "sizeof(char)      = " << sizeof(char) << '\n';
    std::cout << "sizeof(short)     = " << sizeof(short) << '\n';
    std::cout << "sizeof(int)       = " << sizeof(int) << '\n';
    std::cout << "sizeof(long)      = " << sizeof(long) << '\n';
    std::cout << "sizeof(long long) = " << sizeof(long long) << '\n';
    std::cout << "sizeof(float)     = " << sizeof(float) << '\n';
    std::cout << "sizeof(double)    = " << sizeof(double) << '\n';
    std::cout << "sizeof(bool)      = " << sizeof(bool) << '\n';
    std::cout << "sizeof(int*)      = " << sizeof(int*) << '\n';

    // 定长整数类型：不管在哪个平台，宽度都是固定的
    std::cout << "sizeof(std::int32_t)  = " << sizeof(std::int32_t) << '\n';
    std::cout << "sizeof(std::uint64_t) = " << sizeof(std::uint64_t) << '\n';

    // ---------- 2. ASCII 编码 ----------
    // 字符在计算机中存储的是编码值，例如 'A' 的 ASCII 码是 65
    char letter = 'A';
    int code = static_cast<int>(letter);

    std::cout << "\n===== ASCII =====" << '\n';
    std::cout << "letter = " << letter << '\n';
    std::cout << "ASCII code of letter = " << code << '\n';
    std::cout << "character with code 66 = " << static_cast<char>(66) << '\n';

    // ---------- 3. 类型转换 ----------
    // 隐式转换：编译器自动完成，可能丢失精度
    int integer_value = 10;
    double double_value = integer_value; // int -> double，安全

    // 显式转换：使用 static_cast，意图更清晰
    double pi = 3.14159;
    int truncated = static_cast<int>(pi); // double -> int，小数部分被丢弃

    std::cout << "\n===== conversion =====" << '\n';
    std::cout << "double_value = " << double_value << '\n';
    std::cout << "pi = " << pi << '\n';
    std::cout << "truncated = " << truncated << '\n';

    // 字符和整数之间也可以转换
    char digit = '7';
    int digit_value = digit - '0'; // 利用 ASCII 码计算数字值
    std::cout << "digit_value = " << digit_value << '\n';

    // ---------- 4. 作用域 ----------
    int local_number = 10; // 局部变量：存放在栈区

    std::cout << "\n===== scope =====" << '\n';
    std::cout << "global_number = " << global_number << '\n';
    std::cout << "local_number  = " << local_number << '\n';

    {
        // 代码块作用域，block_number 只在这个花括号内有效
        int block_number = 20;
        std::cout << "block_number  = " << block_number << '\n';
    }

    // ---------- 5. 内存区域 ----------
    // 栈区：局部变量，由编译器自动分配和释放
    int stack_value = 1;
    // 静态区：static 局部变量，只初始化一次，程序结束时释放
    static int static_value = 2;
    // 堆区：使用 new 手动申请，使用 delete 手动释放
    int* heap_value = new int(3);

    std::cout << "\n===== memory regions =====" << '\n';
    std::cout << "global variable address: " << static_cast<const void*>(&global_number) << '\n';
    std::cout << "static variable address: " << static_cast<const void*>(&static_value) << '\n';
    std::cout << "stack variable address:  " << static_cast<const void*>(&stack_value) << '\n';
    std::cout << "heap variable address:   " << static_cast<const void*>(heap_value) << '\n';
    std::cout << "heap value: " << *heap_value << '\n';

    delete heap_value;   // 释放堆内存
    heap_value = nullptr; // 避免悬空指针

    // ---------- 6. 数值范围 ----------
    // 有符号和无符号类型的取值范围不同
    std::cout << "\n===== limits =====" << '\n';
    std::cout << "int min = " << std::numeric_limits<int>::min() << '\n';
    std::cout << "int max = " << std::numeric_limits<int>::max() << '\n';
    std::cout << "unsigned int max = " << std::numeric_limits<unsigned int>::max() << '\n';

    // ---------- 7. 编译过程（了解） ----------
    // 预处理：展开 #include、宏替换
    // 编译：把 .cpp 翻译成汇编 / 目标文件
    // 汇编：把汇编代码翻译成机器指令
    // 链接：把多个目标文件和库链接成可执行文件
    //
    // 平时使用一条 g++ 命令，编译器会自动完成上述步骤：
    // g++ -std=c++17 02_memory_and_types.cpp -o 02_memory_and_types.exe

    return 0;
}

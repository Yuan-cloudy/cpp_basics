// 对应文档：docs/17-表达式和作用域.md
// 知识点：表达式语句、作用域、if/switch、for/while/do-while、break/continue、异常
// 编译：g++ -std=c++17 -Wall -Wextra -g 17_control_flow.cpp -o 17_control_flow.exe

#include <iostream>
#include <stdexcept>

// 全局变量：在所有函数外部定义，整个文件都可以访问
int global_value = 100;

int main() {
    // ---------- 1. 表达式语句与声明语句 ----------
    int a = 5;       // 声明并初始化
    a = a + 10;      // 赋值表达式语句
    std::cout << "a = " << a << '\n';

    // ---------- 2. 作用域 ----------
    // 全局变量和局部变量可以同名，局部变量会遮蔽（隐藏）全局变量
    int local_value = 10;
    std::cout << "global_value = " << global_value << '\n';
    std::cout << "local_value  = " << local_value << '\n';

    {
        // 代码块作用域：block_value 只在这个花括号内有效
        int block_value = 20;
        std::cout << "inside block, block_value = " << block_value << '\n';

        // 同名局部变量遮蔽外层的 local_value
        int local_value = 99;
        std::cout << "inside block, local_value = " << local_value << '\n';
    }
    // 离开代码块后，block_value 已经不可见
    std::cout << "outside block, local_value = " << local_value << '\n';

    // ---------- 3. if / else if / else ----------
    int score = 78;

    if (score >= 90) {
        std::cout << "grade: A" << '\n';
    } else if (score >= 80) {
        std::cout << "grade: B" << '\n';
    } else if (score >= 60) {
        std::cout << "grade: C" << '\n';
    } else {
        std::cout << "grade: D" << '\n';
    }

    // ---------- 4. switch ----------
    int day = 3;

    switch (day) {
        case 1:
            std::cout << "Monday" << '\n';
            break; // 不加 break 会继续执行下一个 case（穿透）
        case 2:
            std::cout << "Tuesday" << '\n';
            break;
        case 3:
            std::cout << "Wednesday" << '\n';
            break;
        default:
            std::cout << "Unknown day" << '\n';
            break;
    }

    // ---------- 5. for 循环 ----------
    std::cout << "for: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // ---------- 6. while 循环 ----------
    int count = 5;
    std::cout << "while: ";
    while (count > 0) {
        std::cout << count << ' ';
        --count;
    }
    std::cout << '\n';

    // ---------- 7. do-while 循环 ----------
    // do-while 至少会执行一次循环体
    int number = 0;
    std::cout << "do-while: ";
    do {
        std::cout << number << ' ';
        ++number;
    } while (number < 3);
    std::cout << '\n';

    // ---------- 8. 嵌套循环 ----------
    std::cout << "nested loop:" << '\n';
    for (int row = 1; row <= 3; ++row) {
        for (int col = 1; col <= 3; ++col) {
            std::cout << '(' << row << ',' << col << ") ";
        }
        std::cout << '\n';
    }

    // ---------- 9. break 与 continue ----------
    std::cout << "break/continue: ";
    for (int i = 0; i < 10; ++i) {
        if (i == 5) {
            break; // 直接结束整个循环
        }
        if (i % 2 == 0) {
            continue; // 跳过本次循环剩余语句，进入下一次循环
        }
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // ---------- 10. 异常处理（选学） ----------
    try {
        int age = -1;
        if (age < 0) {
            throw std::runtime_error("age cannot be negative");
        }
        std::cout << "age = " << age << '\n';
    } catch (const std::exception& e) {
        std::cout << "caught exception: " << e.what() << '\n';
    }

    return 0;
}

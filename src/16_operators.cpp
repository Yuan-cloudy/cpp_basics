// 对应文档：docs/16-运算符详解.md
// 知识点：算术、关系、逻辑、位、赋值、复合赋值、条件、自增自减、优先级
// 编译：g++ -std=c++17 -Wall -Wextra -g 16_operators.cpp -o 16_operators.exe

#include <iostream>
#include <string>

int main() {
    std::cout << std::boolalpha; // 让 bool 输出 true/false

    // ---------- 1. 算术运算符 ----------
    int a = 10;
    int b = 3;

    std::cout << "===== arithmetic =====" << '\n';
    std::cout << "a + b  = " << (a + b) << '\n';
    std::cout << "a - b  = " << (a - b) << '\n';
    std::cout << "a * b  = " << (a * b) << '\n';
    // 两个整数相除，结果仍然是整数，小数部分会被截断
    std::cout << "a / b  = " << (a / b) << '\n';
    std::cout << "a % b  = " << (a % b) << '\n'; // 取余，操作数必须是整数

    // 只要有一个操作数是浮点数，结果就是浮点数
    std::cout << "a / 3.0 = " << (a / 3.0) << '\n';

    // ---------- 2. 关系运算符 ----------
    std::cout << "\n===== relational =====" << '\n';
    std::cout << "a == b : " << (a == b) << '\n';
    std::cout << "a != b : " << (a != b) << '\n';
    std::cout << "a >  b : " << (a > b) << '\n';
    std::cout << "a >= b : " << (a >= b) << '\n';

    // ---------- 3. 逻辑运算符 ----------
    bool x = true;
    bool y = false;

    std::cout << "\n===== logical =====" << '\n';
    std::cout << "x && y : " << (x && y) << '\n'; // 逻辑与：两个都为真才为真
    std::cout << "x || y : " << (x || y) << '\n'; // 逻辑或：一个为真就为真
    std::cout << "!x     : " << (!x) << '\n';     // 逻辑非

    // 短路求值：&& 左边为假时，右边不会执行
    int value = 0;
    bool result = (value != 0) && (10 / value > 1);
    std::cout << "short-circuit result: " << result << '\n';

    // ---------- 4. 位运算符 ----------
    // 位运算直接操作整数的二进制位
    unsigned int m = 0b1100; // 二进制字面量（C++14）
    unsigned int n = 0b1010;

    std::cout << "\n===== bitwise =====" << '\n';
    std::cout << "m & n  = " << (m & n) << '\n';  // 按位与
    std::cout << "m | n  = " << (m | n) << '\n';  // 按位或
    std::cout << "m ^ n  = " << (m ^ n) << '\n';  // 按位异或
    std::cout << "~m     = " << (~m) << '\n';     // 按位取反
    std::cout << "m << 1 = " << (m << 1) << '\n'; // 左移一位，相当于乘 2
    std::cout << "m >> 1 = " << (m >> 1) << '\n'; // 右移一位，相当于除以 2

    // ---------- 5. 赋值与复合赋值 ----------
    int number = 100;
    number += 10; // 等价于 number = number + 10;
    number -= 5;
    number *= 2;
    number /= 3;

    std::cout << "\n===== assignment =====" << '\n';
    std::cout << "number = " << number << '\n';

    // ---------- 6. 自增和自减 ----------
    int i = 5;

    std::cout << "\n===== increment =====" << '\n';
    std::cout << "i      = " << i << '\n';
    std::cout << "i++    = " << i++ << " (先取值，后自增)" << '\n';
    std::cout << "after  = " << i << '\n';
    std::cout << "++i    = " << ++i << " (先自增，后取值)" << '\n';

    // ---------- 7. 条件运算符 ----------
    int score = 82;
    std::string level = (score >= 60) ? "pass" : "fail";

    std::cout << "\n===== ternary =====" << '\n';
    std::cout << "score = " << score << ", level = " << level << '\n';

    // ---------- 8. sizeof 运算符 ----------
    std::cout << "\n===== sizeof =====" << '\n';
    std::cout << "sizeof(int)    = " << sizeof(int) << " bytes" << '\n';
    std::cout << "sizeof(double) = " << sizeof(double) << " bytes" << '\n';

    // ---------- 9. 优先级与括号 ----------
    // 乘除优先级高于加减；不确定时加括号，代码更清晰
    int p = 2 + 3 * 4;
    int q = (2 + 3) * 4;

    std::cout << "\n===== precedence =====" << '\n';
    std::cout << "2 + 3 * 4   = " << p << '\n';
    std::cout << "(2 + 3) * 4 = " << q << '\n';

    return 0;
}

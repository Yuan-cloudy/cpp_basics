// 对应文档：docs/05-引用类型.md
// 知识点：引用的定义、引用传参、引用返回、左值引用、右值引用、移动语义
// 编译：g++ -std=c++17 -Wall -Wextra -g 05_reference.cpp -o 05_reference.exe
//
// 说明：
// 1. 引用是已经存在的变量的别名，必须在定义时初始化，之后不能改为引用别的变量。
// 2. 引用本身不占用额外的对象空间（具体由编译器实现），使用方式和普通变量一样。
// 3. 左值引用使用 &，右值引用使用 &&。

#include <iostream>
#include <string>
#include <utility>

// 通过引用修改实参：函数内部修改的就是外面的变量
void addTen(int& value) {
    value += 10;
}

// const 引用可以读取实参，但不允许通过引用修改
void printValue(const int& value) {
    std::cout << "value = " << value << '\n';
}

// 返回引用：返回的是外部变量的别名，调用方可以直接修改原变量
int& getReference(int& value) {
    return value;
}

// 右值引用可以绑定临时对象，常用于移动语义和完美转发
void printRvalue(int&& value) {
    std::cout << "rvalue = " << value << '\n';
}

int main() {
    // ---------- 1. 引用的基本用法 ----------
    int number = 10;
    int& ref = number; // ref 是 number 的别名

    std::cout << "===== reference basics =====" << '\n';
    std::cout << "number = " << number << '\n';
    std::cout << "ref    = " << ref << '\n';

    ref = 20; // 修改 ref 就是修改 number
    std::cout << "after ref = 20, number = " << number << '\n';

    // ---------- 2. 引用作为函数参数 ----------
    std::cout << "\n===== reference parameter =====" << '\n';
    int value = 5;
    std::cout << "before addTen: " << value << '\n';
    addTen(value);
    std::cout << "after addTen:  " << value << '\n';

    // const 引用可以接受左值，也可以接受临时对象
    printValue(value);
    const int& const_ref = 42; // 临时值 42 的生命周期被延长
    printValue(const_ref);

    // ---------- 3. 返回引用 ----------
    std::cout << "\n===== return reference =====" << '\n';
    int original = 100;
    int& returned = getReference(original);
    returned = 200; // 通过返回的引用修改 original
    std::cout << "original = " << original << '\n';

    // 注意：不要返回局部变量的引用，函数结束后局部变量已经被销毁
    // int& bad() {
    //     int local = 10;
    //     return local; // 错误：返回悬空引用
    // }

    // ---------- 4. 左值引用与右值引用 ----------
    std::cout << "\n===== lvalue / rvalue =====" << '\n';
    int lvalue = 7;
    int& lvalue_ref = lvalue; // 左值引用绑定左值
    std::cout << "lvalue_ref = " << lvalue_ref << '\n';

    printRvalue(123); // 123 是临时值（右值），可以绑定到右值引用

    // ---------- 5. 移动语义 ----------
    // std::move 把左值转换为右值引用，表示“这个对象的资源可以被移动”
    // 移动之后，原对象仍然有效，但内容是不确定的，不应再依赖它的值
    std::cout << "\n===== move semantics =====" << '\n';
    std::string source = "a long string that can be moved";
    std::string target = std::move(source);

    std::cout << "target = " << target << '\n';
    std::cout << "source is still valid, but its value is unspecified" << '\n';

    // 移动语义的主要价值：避免不必要的深拷贝，提高性能
    // 例如 std::string、std::vector 等容器在移动时通常只转移内部指针

    return 0;
}

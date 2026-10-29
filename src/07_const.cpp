// 对应文档：docs/07-const修饰符.md
// 知识点：const 变量、const 引用、指向常量的指针、常量指针、constexpr
// 编译：g++ -std=c++17 -Wall -Wextra -g 07_const.cpp -o 07_const.exe
//
// 说明：
// 1. const 表示“只读”，变量初始化后不能再修改。
// 2. const 可以修饰变量、引用、指针，也可以修饰函数参数。
// 3. 阅读指针声明时，从右往左读更容易理解 const 修饰的是谁。

#include <iostream>

// const 引用：既能避免拷贝，又保证函数内部不会修改实参
void printValue(const int& value) {
    std::cout << "value = " << value << '\n';
    // value = 100; // 错误：不能通过 const 引用修改对象
}

// constexpr 函数：参数是常量表达式时，可以在编译期计算结果
constexpr int square(int value) {
    return value * value;
}

int main() {
    // ---------- 1. const 变量 ----------
    const int max_value = 100;
    // max_value = 200; // 错误：const 变量不能被修改

    int runtime_value = 10;
    const int copied_value = runtime_value; // 可以用变量初始化 const 变量

    std::cout << "===== const variable =====" << '\n';
    std::cout << "max_value = " << max_value << '\n';
    std::cout << "copied_value = " << copied_value << '\n';

    // ---------- 2. const 引用 ----------
    std::cout << "\n===== const reference =====" << '\n';
    int number = 42;
    const int& const_ref = number;

    std::cout << "const_ref = " << const_ref << '\n';
    // const_ref = 50; // 错误：不能通过 const 引用修改
    number = 50;       // 原变量本身可以修改
    std::cout << "after number = 50, const_ref = " << const_ref << '\n';

    // const 引用也可以绑定临时值，临时值的生命周期会被延长
    const int& temporary_ref = 123;
    printValue(temporary_ref);
    printValue(456);

    // ---------- 3. 指向常量的指针 ----------
    // const int* ptr：ptr 指向的内容是只读的，但 ptr 本身可以改变指向
    std::cout << "\n===== pointer to const =====" << '\n';
    int first = 10;
    int second = 20;

    const int* ptr_to_const = &first;
    std::cout << "*ptr_to_const = " << *ptr_to_const << '\n';
    // *ptr_to_const = 11; // 错误：不能通过该指针修改内容
    ptr_to_const = &second; // 正确：指针本身可以改为指向别的对象
    std::cout << "after pointing to second, *ptr_to_const = " << *ptr_to_const << '\n';

    // ---------- 4. 常量指针 ----------
    // int* const ptr：ptr 本身是只读的，不能改变指向，但可以通过它修改内容
    std::cout << "\n===== const pointer =====" << '\n';
    int* const const_ptr = &first;
    *const_ptr = 11; // 正确：修改指向的内容
    // const_ptr = &second; // 错误：不能修改指针本身的指向
    std::cout << "first = " << first << '\n';

    // ---------- 5. 指向常量的常量指针 ----------
    // const int* const ptr：内容和指针本身都不能修改
    std::cout << "\n===== const pointer to const =====" << '\n';
    const int* const const_ptr_to_const = &second;
    std::cout << "*const_ptr_to_const = " << *const_ptr_to_const << '\n';
    // *const_ptr_to_const = 21; // 错误
    // const_ptr_to_const = &first; // 错误

    // ---------- 6. constexpr ----------
    // constexpr 表示“常量表达式”，要求能在编译期求出结果
    std::cout << "\n===== constexpr =====" << '\n';
    constexpr int side = 5;
    constexpr int area = square(side);

    static_assert(square(3) == 9, "square(3) should be 9");

    std::cout << "side = " << side << '\n';
    std::cout << "area = " << area << '\n';

    // ---------- 7. 顶层 const 与底层 const（了解） ----------
    // 顶层 const：对象本身是常量，例如 int* const p;
    // 底层 const：指针/引用指向的对象是常量，例如 const int* p;
    // 函数按值传参时，顶层 const 会被忽略；底层 const 会影响能接受的实参类型。
    printValue(first);

    return 0;
}

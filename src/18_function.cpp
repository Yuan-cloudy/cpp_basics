// 对应文档：docs/18-函数用法.md
// 知识点：函数声明/定义、参数传递、返回值、重载、默认参数、递归、Lambda、函数指针
// 编译：g++ -std=c++17 -Wall -Wextra -g 18_function.cpp -o 18_function.exe
//
// 说明：
// 1. 函数声明告诉编译器函数的名字、参数和返回值；函数定义提供函数体。
// 2. 参数传递方式：传值、传引用、传指针。
// 3. 重载：函数名相同，但参数列表不同。

#include <iostream>
#include <string>

// ---------- 函数声明 ----------
// 声明可以写在调用之前，定义可以写在文件后面
int add(int a, int b);

void addOne(int& value);       // 传引用
void addOne(int* value);       // 传指针（与上面的引用版本构成重载）
void addOneByValue(int value); // 传值

int& getElement(int& value);   // 返回引用
int* maxPtr(int* a, int* b);   // 返回指针

int square(int value);         // 重载版本 1
double square(double value);   // 重载版本 2

int sum(int a, int b = 10);    // 带默认参数

inline int multiply(int a, int b); // 内联函数

int factorial(int n);          // 递归函数

int triple(int value);         // 普通函数，后面用函数指针指向它
int apply(int (*operation)(int), int value); // 函数指针作为参数

std::string makeGreeting(const std::string& name); // 返回对象

int main() {
    // ---------- 1. 基本调用 ----------
    std::cout << "===== function call =====" << '\n';
    std::cout << "add(3, 4) = " << add(3, 4) << '\n';
    std::cout << "add(10, 20) = " << add(10, 20) << '\n';

    // ---------- 2. 参数传递 ----------
    std::cout << "\n===== parameter passing =====" << '\n';

    int value = 10;
    std::cout << "before addOne(ref): " << value << '\n';
    addOne(value); // 传引用
    std::cout << "after addOne(ref):  " << value << '\n';

    std::cout << "before addOne(ptr): " << value << '\n';
    addOne(&value); // 传指针
    std::cout << "after addOne(ptr):  " << value << '\n';

    // 传值：函数拿到的是副本，修改副本不会影响实参
    int copied = value;
    addOneByValue(copied);
    std::cout << "after addOneByValue: " << copied << '\n';

    // ---------- 3. 返回引用与返回指针 ----------
    std::cout << "\n===== return reference / pointer =====" << '\n';
    int original = 100;
    int& ref = getElement(original);
    ref = 200;
    std::cout << "original = " << original << '\n';

    int a = 30;
    int b = 50;
    int* larger = maxPtr(&a, &b);
    std::cout << "larger value = " << *larger << '\n';

    // ---------- 4. 函数重载 ----------
    std::cout << "\n===== overload =====" << '\n';
    std::cout << "square(5)   = " << square(5) << '\n';
    std::cout << "square(2.5) = " << square(2.5) << '\n';

    // ---------- 5. 默认参数 ----------
    std::cout << "\n===== default argument =====" << '\n';
    std::cout << "sum(5)    = " << sum(5) << '\n';
    std::cout << "sum(5, 6) = " << sum(5, 6) << '\n';

    // ---------- 6. 内联函数 ----------
    std::cout << "\n===== inline =====" << '\n';
    std::cout << "multiply(3, 4) = " << multiply(3, 4) << '\n';

    // ---------- 7. 递归 ----------
    std::cout << "\n===== recursion =====" << '\n';
    std::cout << "factorial(5) = " << factorial(5) << '\n';

    // ---------- 8. Lambda 表达式 ----------
    // Lambda 是匿名函数，适合写简短的、一次性的逻辑
    std::cout << "\n===== lambda =====" << '\n';
    auto add_lambda = [](int x, int y) {
        return x + y;
    };

    int base = 100;
    auto add_base = [base](int x) {
        return x + base;
    };

    std::cout << "add_lambda(2, 3) = " << add_lambda(2, 3) << '\n';
    std::cout << "add_base(5)      = " << add_base(5) << '\n';

    // ---------- 9. 函数指针与回调 ----------
    std::cout << "\n===== function pointer =====" << '\n';
    int (*func_ptr)(int) = triple; // 函数指针指向 triple
    std::cout << "func_ptr(4) = " << func_ptr(4) << '\n';
    std::cout << "apply(triple, 5) = " << apply(triple, 5) << '\n';

    // ---------- 10. 返回对象 ----------
    std::cout << "\n===== return object =====" << '\n';
    std::string greeting = makeGreeting("C++ learner");
    std::cout << greeting << '\n';

    return 0;
}

// ---------- 函数定义 ----------
int add(int a, int b) {
    return a + b;
}

void addOne(int& value) {
    value += 1;
}

void addOne(int* value) {
    if (value != nullptr) {
        *value += 1;
    }
}

void addOneByValue(int value) {
    value += 1; // 只修改副本
}

int& getElement(int& value) {
    return value;
}

int* maxPtr(int* a, int* b) {
    if (*a > *b) {
        return a;
    }
    return b;
}

int square(int value) {
    return value * value;
}

double square(double value) {
    return value * value;
}

int sum(int a, int b) {
    return a + b;
}

inline int multiply(int a, int b) {
    return a * b;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int triple(int value) {
    return value * 3;
}

int apply(int (*operation)(int), int value) {
    return operation(value);
}

std::string makeGreeting(const std::string& name) {
    return "Hello, " + name + "!";
}

// 对应文档：docs/10-using命名空间.md
// 知识点：命名空间、作用域运算符 ::、using 声明、using namespace
// 编译：g++ -std=c++17 -Wall -Wextra -g 10_namespace.cpp -o 10_namespace.exe
//
// 说明：
// 1. std 是 C++ 标准库所在的命名空间，所以标准库名字通常写成 std::cout。
// 2. using std::cout; 只引入一个名字，比较推荐。
// 3. using namespace std; 会把整个命名空间的名字都引入，容易产生名字冲突，
//    在大型项目或头文件中通常不推荐使用。

#include <iostream>

// 自定义命名空间：把相关的函数、变量放在一起，避免和别人的代码重名
namespace math {
    int add(int a, int b) {
        return a + b;
    }

    int multiply(int a, int b) {
        return a * b;
    }
}

namespace text {
    const char* greeting() {
        return "hello from text namespace";
    }
}

// 只引入 std::cout 和 std::endl 这两个名字
using std::cout;
using std::endl;

int main() {
    // 使用作用域运算符 :: 访问命名空间中的成员
    cout << "math::add(2, 3) = " << math::add(2, 3) << endl;
    cout << "math::multiply(2, 3) = " << math::multiply(2, 3) << endl;
    cout << text::greeting() << endl;

    // 引入名字之后，就可以省略 std:: 前缀
    // 注意：这里只是引入 cout，没有引入 cin
    cout << "using std::cout works" << endl;

    // 不推荐在全局范围写 using namespace std;
    // 这里仅做演示，并把它限制在代码块内部，减少影响范围
    {
        using namespace math;
        // 在这个代码块中可以直接调用 add 和 multiply
        cout << "add(4, 5) = " << add(4, 5) << endl;
        cout << "multiply(4, 5) = " << multiply(4, 5) << endl;
    }

    // 离开上面的代码块后，仍然需要使用 math:: 前缀
    cout << "math::add(10, 20) = " << math::add(10, 20) << endl;

    return 0;
}

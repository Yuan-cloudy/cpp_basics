// 对应文档：docs/09-结构体类型.md
// 知识点：结构体定义、成员访问、聚合初始化、嵌套结构体、结构体中的函数
// 编译：g++ -std=c++17 -Wall -Wextra -g 09_struct.cpp -o 09_struct.exe
//
// 说明：
// 1. struct 用来把多个不同类型的数据组合成一个整体。
// 2. 结构体成员默认是 public 的；class 的成员默认是 private 的，这是二者的主要区别之一。
// 3. 结构体也可以包含成员函数，但更复杂的封装通常交给 class。

#include <iostream>
#include <string>

// 定义一个表示二维坐标点的结构体
struct Point {
    int x;
    int y;

    // 成员函数：可以直接访问结构体的成员变量
    int sum() const {
        return x + y;
    }
};

// 嵌套结构体：矩形由两个点组成
struct Rectangle {
    Point top_left;
    Point bottom_right;

    // 成员函数声明，定义写在结构体外面
    int width() const;
    int height() const;
    int area() const;
};

// 结构体中的字符串成员
struct Student {
    std::string name;
    int age;

    void introduce() const {
        std::cout << "name: " << name << ", age: " << age << '\n';
    }
};

// 结构体作为函数参数，使用 const 引用避免拷贝
void printPoint(const Point& point) {
    std::cout << "(" << point.x << ", " << point.y << ")" << '\n';
}

// Rectangle 成员函数的定义
int Rectangle::width() const {
    return bottom_right.x - top_left.x;
}

int Rectangle::height() const {
    return bottom_right.y - top_left.y;
}

int Rectangle::area() const {
    return width() * height();
}

int main() {
    // ---------- 1. 结构体的定义与初始化 ----------
    // 聚合初始化：按成员声明顺序依次赋值
    Point p1{3, 4};
    Point p2 = {10, 20};

    std::cout << "===== point =====" << '\n';
    std::cout << "p1.x = " << p1.x << ", p1.y = " << p1.y << '\n';
    std::cout << "p2.x = " << p2.x << ", p2.y = " << p2.y << '\n';
    std::cout << "p1.sum() = " << p1.sum() << '\n';

    // ---------- 2. 成员访问与修改 ----------
    p1.x = 100;
    p1.y = 200;
    std::cout << "\n===== modify member =====" << '\n';
    std::cout << "after modify, p1 = ";
    printPoint(p1);

    // ---------- 3. 结构体指针 ----------
    Point* ptr = &p1;
    std::cout << "\n===== struct pointer =====" << '\n';
    std::cout << "ptr->x = " << ptr->x << '\n'; // -> 等价于 (*ptr).x
    std::cout << "(*ptr).y = " << (*ptr).y << '\n';
    ptr->x = 7;
    std::cout << "after ptr->x = 7, p1.x = " << p1.x << '\n';

    // ---------- 4. 嵌套结构体 ----------
    Rectangle rect{{0, 0}, {4, 3}};

    std::cout << "\n===== nested struct =====" << '\n';
    std::cout << "width  = " << rect.width() << '\n';
    std::cout << "height = " << rect.height() << '\n';
    std::cout << "area   = " << rect.area() << '\n';

    // 嵌套成员的访问：先访问外层成员，再访问内层成员
    std::cout << "top_left = ";
    printPoint(rect.top_left);
    std::cout << "bottom_right = ";
    printPoint(rect.bottom_right);

    // ---------- 5. 结构体中的字符串与成员函数 ----------
    Student student{"Xiao Ming", 18};

    std::cout << "\n===== struct with function =====" << '\n';
    student.introduce();

    // ---------- 6. 结构体与类的比较 ----------
    // struct 默认 public，class 默认 private。
    // 在 C++ 中，struct 也可以有构造函数、成员函数、继承等特性，
    // 但习惯上：
    // - 只是组合数据、成员都公开时，用 struct；
    // - 需要封装、隐藏实现细节时，用 class。
    std::cout << "\n===== struct vs class =====" << '\n';
    std::cout << "struct members are public by default" << '\n';

    return 0;
}

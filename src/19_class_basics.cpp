// 对应文档：docs/19-类的基本用法.md（拓展内容，不强制）
// 知识点：类与对象、访问控制、构造/析构、拷贝/移动、运算符重载、友元
// 编译：g++ -std=c++17 -Wall -Wextra -g 19_class_basics.cpp -o 19_class_basics.exe
//
// 说明：
// 1. class 的成员默认是 private，struct 的成员默认是 public。
// 2. 构造函数负责初始化对象，析构函数负责清理资源。
// 3. 拷贝构造/拷贝赋值用于复制对象；移动构造/移动赋值用于转移资源。
// 4. 运算符重载让自定义类型像内置类型一样使用运算符。

#include <iostream>
#include <string>
#include <utility>

class Student {
public:
    // 构造函数
    Student(const std::string& name, int age)
        : name_(name), age_(age) {
        std::cout << "Student constructed: " << name_ << '\n';
    }

    // 拷贝构造函数：用另一个对象初始化新对象
    Student(const Student& other)
        : name_(other.name_), age_(other.age_) {
        std::cout << "Student copy constructed: " << name_ << '\n';
    }

    // 移动构造函数：接管另一个对象的资源
    // noexcept 告诉编译器移动操作不会抛出异常，容器扩容时更愿意使用移动
    Student(Student&& other) noexcept
        : name_(std::move(other.name_)), age_(other.age_) {
        other.age_ = 0;
        std::cout << "Student move constructed: " << name_ << '\n';
    }

    // 拷贝赋值运算符
    Student& operator=(const Student& other) {
        std::cout << "Student copy assigned: " << other.name_ << '\n';
        if (this != &other) {
            name_ = other.name_;
            age_ = other.age_;
        }
        return *this;
    }

    // 移动赋值运算符
    Student& operator=(Student&& other) noexcept {
        std::cout << "Student move assigned: " << other.name_ << '\n';
        if (this != &other) {
            name_ = std::move(other.name_);
            age_ = other.age_;
            other.age_ = 0;
        }
        return *this;
    }

    // 析构函数：对象销毁时自动调用
    ~Student() {
        std::cout << "Student destructed: " << name_ << '\n';
    }

    // const 成员函数：承诺不修改对象状态，const 对象也可以调用
    const std::string& name() const {
        return name_;
    }

    int age() const {
        return age_;
    }

    void setAge(int age) {
        if (age >= 0) {
            age_ = age;
        }
    }

    // 友元函数：可以访问 Student 的私有成员
    friend std::ostream& operator<<(std::ostream& os, const Student& student);

private:
    std::string name_;
    int age_;
};

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student(" << student.name_ << ", " << student.age_ << ")";
    return os;
}

// 再定义一个二维向量类，演示运算符重载
class Vec2 {
public:
    Vec2(int x, int y) : x_(x), y_(y) {}

    // 成员函数方式重载 +
    Vec2 operator+(const Vec2& other) const {
        return Vec2(x_ + other.x_, y_ + other.y_);
    }

    // 成员函数方式重载 ==
    bool operator==(const Vec2& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    // 友元方式重载 <<
    friend std::ostream& operator<<(std::ostream& os, const Vec2& vec);

private:
    int x_;
    int y_;
};

std::ostream& operator<<(std::ostream& os, const Vec2& vec) {
    os << "(" << vec.x_ << ", " << vec.y_ << ")";
    return os;
}

int main() {
    std::cout << "===== class basics =====" << '\n';

    // 构造对象
    Student alice("Alice", 20);
    std::cout << alice << '\n';

    // 修改私有成员只能通过公开成员函数
    alice.setAge(21);
    std::cout << "after setAge: " << alice << '\n';

    // 拷贝构造
    std::cout << "\n===== copy =====" << '\n';
    Student bob = alice;
    std::cout << bob << '\n';

    // 移动构造
    std::cout << "\n===== move =====" << '\n';
    Student carol = std::move(bob);
    std::cout << carol << '\n';
    std::cout << "bob is still valid, but its value is unspecified" << '\n';

    // 拷贝赋值
    std::cout << "\n===== copy assignment =====" << '\n';
    Student dave("Dave", 19);
    dave = carol;
    std::cout << dave << '\n';

    // 移动赋值：右侧是临时对象，会调用移动赋值
    std::cout << "\n===== move assignment =====" << '\n';
    dave = Student("Eve", 22);
    std::cout << dave << '\n';

    // 运算符重载
    std::cout << "\n===== operator overload =====" << '\n';
    Vec2 v1(1, 2);
    Vec2 v2(3, 4);
    Vec2 v3 = v1 + v2;

    std::cout << "v1 = " << v1 << '\n';
    std::cout << "v2 = " << v2 << '\n';
    std::cout << "v3 = v1 + v2 = " << v3 << '\n';
    std::cout << "v1 == v2: " << std::boolalpha << (v1 == v2) << '\n';
    std::cout << "v1 == v1: " << (v1 == v1) << '\n';

    // 程序结束时，栈上的对象按构造的逆序自动析构
    return 0;
}

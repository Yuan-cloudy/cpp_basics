// 对应文档：docs/06-指针类型.md
// 知识点：指针基础、取地址与解引用、空指针、void*、多级指针、指针运算
// 编译：g++ -std=c++17 -Wall -Wextra -g 06_pointer.cpp -o 06_pointer.exe
//
// 说明：
// 1. 指针保存的是变量的地址，类型写成“指向的类型*”，例如 int*。
// 2. & 取地址，* 解引用（访问指针指向的对象）。
// 3. 指针必须指向有效对象或为 nullptr，不能解引用空指针或野指针。

#include <iostream>

// 通过指针修改外部变量
void setToZero(int* ptr) {
    if (ptr != nullptr) {
        *ptr = 0;
    }
}

int main() {
    std::cout << std::boolalpha; // 让 bool 输出 true/false

    // ---------- 1. 指针的定义与使用 ----------
    int number = 10;
    int* ptr = &number; // ptr 保存 number 的地址

    std::cout << "===== pointer basics =====" << '\n';
    std::cout << "number = " << number << '\n';
    std::cout << "address of number = " << static_cast<const void*>(&number) << '\n';
    std::cout << "ptr = " << static_cast<const void*>(ptr) << '\n';
    std::cout << "*ptr = " << *ptr << '\n';

    // 通过指针修改对象
    *ptr = 20;
    std::cout << "after *ptr = 20, number = " << number << '\n';

    // ---------- 2. 空指针 ----------
    int* null_ptr = nullptr; // C++11 推荐用 nullptr，不推荐 NULL 或 0
    std::cout << "\n===== null pointer =====" << '\n';
    std::cout << "null_ptr is null: " << (null_ptr == nullptr) << '\n';

    // 使用指针前必须判空
    if (null_ptr != nullptr) {
        std::cout << *null_ptr << '\n';
    } else {
        std::cout << "null_ptr is null, cannot dereference" << '\n';
    }

    // ---------- 3. 通过指针传参 ----------
    std::cout << "\n===== pointer parameter =====" << '\n';
    int value = 99;
    std::cout << "before setToZero: " << value << '\n';
    setToZero(&value);
    std::cout << "after setToZero:  " << value << '\n';

    // ---------- 4. 万能指针 void* ----------
    // void* 可以保存任意对象地址，但不能直接解引用，必须先转换回具体类型
    std::cout << "\n===== void pointer =====" << '\n';
    void* void_ptr = &value;
    int* int_ptr = static_cast<int*>(void_ptr);
    std::cout << "*int_ptr = " << *int_ptr << '\n';

    // ---------- 5. 指向指针的指针 ----------
    std::cout << "\n===== pointer to pointer =====" << '\n';
    int* first = &number;
    int** second = &first; // second 指向 first 这个指针
    std::cout << "**second = " << **second << '\n';
    **second = 30; // 通过二级指针修改 number
    std::cout << "after **second = 30, number = " << number << '\n';

    // ---------- 6. 指向指针的引用 ----------
    // 引用本身不是对象，但可以给指针建立引用，从而修改指针本身
    std::cout << "\n===== reference to pointer =====" << '\n';
    int other = 77;
    int* ptr_ref = &number;
    int*& ref_to_ptr = ptr_ref; // ref_to_ptr 是 ptr_ref 的引用
    ref_to_ptr = &other;        // 修改 ptr_ref，让它指向 other
    std::cout << "*ptr_ref = " << *ptr_ref << '\n';

    // ---------- 7. 指针运算 ----------
    // 指针加 1 表示移动到下一个同类型元素，而不是简单地把地址加 1
    std::cout << "\n===== pointer arithmetic =====" << '\n';
    int arr[5] = {10, 20, 30, 40, 50};
    int* begin = arr;            // 数组名在大多数情况下会转换为首元素地址
    int* end = arr + 5;          // 尾后指针，指向最后一个元素的下一个位置

    std::cout << "sizeof(int*) = " << sizeof(int*) << " bytes" << '\n';
    std::cout << "sizeof(int)  = " << sizeof(int) << " bytes" << '\n';

    for (int* p = begin; p != end; ++p) {
        std::cout << *p << ' ';
    }
    std::cout << '\n';

    // 通过下标访问，本质上也是指针运算
    std::cout << "arr[2] = " << arr[2] << '\n';
    std::cout << "*(arr + 2) = " << *(arr + 2) << '\n';

    // 注意：
    // 1. 不要解引用 end（尾后指针），它不指向有效元素。
    // 2. 不要访问数组边界之外的内存。
    // 3. 指针指向的对象销毁后，指针会变成悬空指针，不能再使用。

    return 0;
}

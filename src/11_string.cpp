// 对应文档：docs/11-string类用法.md
// 知识点：std::string 的构造、长度、拼接、查找、截取、修改、遍历、类型转换
// 编译：g++ -std=c++17 -Wall -Wextra -g 11_string.cpp -o 11_string.exe
//
// 说明：
// 1. std::string 是标准库提供的字符串类型，需要包含 <string>。
// 2. string 会自动管理内存，比 C 风格字符数组更安全、更方便。
// 3. 下标越界不会自动检查，不确定时可以用 at()，越界会抛出异常。

#include <cctype>
#include <iostream>
#include <string>

int main() {
    // ---------- 1. 构造与初始化 ----------
    std::string s1 = "hello";
    std::string s2("world");
    std::string s3(5, 'a');       // 5 个字符 'a'
    std::string s4 = s1;          // 拷贝构造
    std::string empty_string;     // 空字符串

    std::cout << "===== construct =====" << '\n';
    std::cout << "s1 = " << s1 << '\n';
    std::cout << "s2 = " << s2 << '\n';
    std::cout << "s3 = " << s3 << '\n';
    std::cout << "s4 = " << s4 << '\n';

    // ---------- 2. 长度与判空 ----------
    std::cout << "\n===== size =====" << '\n';
    std::cout << "s1.size()   = " << s1.size() << '\n';
    std::cout << "s1.length() = " << s1.length() << '\n';
    std::cout << "s1.empty()  = " << std::boolalpha << s1.empty() << '\n';
    std::cout << "empty_string.empty() = " << empty_string.empty() << '\n';

    // ---------- 3. 拼接与追加 ----------
    std::cout << "\n===== append =====" << '\n';
    std::string text = s1 + " " + s2; // 使用 + 拼接，产生新字符串
    std::cout << "text = " << text << '\n';

    text += "!";            // 追加字符串
    text.push_back('?');    // 追加单个字符
    std::cout << "after append: " << text << '\n';

    // ---------- 4. 访问字符 ----------
    std::cout << "\n===== access =====" << '\n';
    std::cout << "text[0]      = " << text[0] << '\n';
    std::cout << "text.front() = " << text.front() << '\n';
    std::cout << "text.back()  = " << text.back() << '\n';
    std::cout << "text.at(1)   = " << text.at(1) << '\n';

    // 修改字符
    text[0] = 'H';
    std::cout << "after text[0] = 'H': " << text << '\n';

    // ---------- 5. 查找 ----------
    std::cout << "\n===== find =====" << '\n';
    std::string sentence = "C++ is a powerful language, C++ is fast.";

    std::size_t first_pos = sentence.find("C++");
    std::size_t second_pos = sentence.find("C++", first_pos + 1);
    std::size_t missing_pos = sentence.find("Java");

    std::cout << "first  \"C++\" position: " << first_pos << '\n';
    std::cout << "second \"C++\" position: " << second_pos << '\n';

    if (missing_pos == std::string::npos) {
        std::cout << "\"Java\" not found" << '\n';
    }

    std::size_t last_pos = sentence.rfind("C++");
    std::cout << "last \"C++\" position: " << last_pos << '\n';

    // ---------- 6. 截取子串 ----------
    std::cout << "\n===== substr =====" << '\n';
    std::string sub = sentence.substr(0, 3); // 从下标 0 开始，取 3 个字符
    std::cout << "substr(0, 3) = " << sub << '\n';

    // ---------- 7. 修改字符串 ----------
    std::cout << "\n===== modify =====" << '\n';
    std::string edit = "I like Java";
    edit.replace(7, 4, "C++"); // 从下标 7 开始，替换 4 个字符
    std::cout << "after replace: " << edit << '\n';

    edit.insert(0, "Hello, "); // 在下标 0 处插入
    std::cout << "after insert: " << edit << '\n';

    edit.erase(0, 7); // 从下标 0 开始删除 7 个字符
    std::cout << "after erase: " << edit << '\n';

    // ---------- 8. 遍历 ----------
    std::cout << "\n===== traverse =====" << '\n';

    // 下标遍历
    std::cout << "by index: ";
    for (std::size_t i = 0; i < s1.size(); ++i) {
        std::cout << s1[i] << ' ';
    }
    std::cout << '\n';

    // 范围 for 遍历，字符是副本；写成 char& 可以修改原字符串
    std::string upper = "hello";
    for (char& ch : upper) {
        ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
    }
    std::cout << "to upper: " << upper << '\n';

    // ---------- 9. 比较 ----------
    std::cout << "\n===== compare =====" << '\n';
    std::string left = "apple";
    std::string right = "banana";

    if (left < right) {
        std::cout << left << " < " << right << '\n';
    }

    // compare 返回 0 表示相等，小于 0 表示左边小，大于 0 表示左边大
    std::cout << "left.compare(right) = " << left.compare(right) << '\n';

    // ---------- 10. 字符串与数字转换 ----------
    std::cout << "\n===== conversion =====" << '\n';
    std::string number_text = "123";
    int number = std::stoi(number_text);       // string -> int
    double decimal = std::stod("3.14");        // string -> double

    std::cout << "number + 1 = " << number + 1 << '\n';
    std::cout << "decimal * 2 = " << decimal * 2 << '\n';

    std::string from_number = std::to_string(2024); // 数字 -> string
    std::cout << "from_number = " << from_number << '\n';

    // ---------- 11. 与 C 风格字符串互转 ----------
    // c_str() 返回一个以 '\0' 结尾的 const char*，用于兼容 C 风格接口
    const char* c_string = sentence.c_str();
    std::cout << "\n===== c_str =====" << '\n';
    std::cout << "first char of c_string = " << c_string[0] << '\n';

    return 0;
}

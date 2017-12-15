#pragma once

/*

练习 13.44：编写标准函数库 string 类的简化版本，命名为 String。你的类应该至少有一个默认构造函数和一个接受 C 风格字符串指针参数的构造函数。
使用 allocator 为你的 String 类分配所需内存

*/

#include <memory>
#include <cstring>      // strlen()
#include <utility>
#include <iostream>
#include <iterator>
#include <algorithm>

class String {
private:
    char *elements;
    char *end;

    std::allocator<char> alloc;     // 分配元素

public:
    String() : String("") { }       // 默认构造字符串时，字符串占一个内存单元，存储 '\0'
    String(const char *s)
    {
        auto newdata = alloc_n_copy(s, s + strlen(s) + 1);      // 分配 strlen(s) + 1 个内存单元，最后一个用来存放空字符 '\0'
        elements = newdata.first;
        end = newdata.second;
    }
    String(const String& rhs)
    {
        auto newdata = alloc_n_copy(rhs.elements, rhs.end);
        elements = newdata.first;
        end = newdata.second;
    }
    String& operator= (const String& rhs)
    {
        auto newdata = alloc_n_copy(rhs.elements, rhs.end);
        free();
        elements = newdata.first;
        end = newdata.second;
        return *this;
    }
    ~String()
    {
        free();
    }

    const char* c_str() { return elements; }
    size_t size() const { return end - elements; }      
    size_t length() const { return end - elements - 1; }    // 最后一个位置用来存放空字符 '\0'
private:
    std::pair<char*, char*> alloc_n_copy(const char *b, const char *e)
    {
        auto data = alloc.allocate(e - b);
        return { data, std::uninitialized_copy(b, e, data) };
    }
    void free()
    {
        if (elements)
        {
            std::for_each(elements, end, [this](char& c) { alloc.destroy(&c); });
            alloc.deallocate(elements, end - elements);
        }
    }
};

/*

#include "String.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    String s("Hello");
    cout << s.c_str() << endl;

    String s2;
    cout << s2.c_str() << endl;
    cout << s2.length() << endl;
    cout << s2.size() << endl;

    String s3 = s;
    cout << s3.c_str() << endl;

    return 0;
}

输出： 

Hello

0
1
Hello
请按任意键继续. . .

*/
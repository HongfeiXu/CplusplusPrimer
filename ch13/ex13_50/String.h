#pragma once

/*

练习 13.44：编写标准函数库 string 类的简化版本，命名为 String。你的类应该至少有一个默认构造函数和一个接受 C 风格字符串指针参数的构造函数。
使用 allocator 为你的 String 类分配所需内存

练习 13.47：对你在练习 13.44 中定义的 String 类，为它的拷贝构造函数拷贝赋值运算符添加一条语句，在每次函数执行时打印一条信息。

练习 13.48：定义一个 vector<String> 并在其上多次调用 push_back。运行你的程序，并观察 String 被拷贝了多少次。

*/

#include <memory>
#include <cstring>      // strlen()
#include <utility>		// move
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
		std::cout << "String::Constructor" << std::endl;
		auto newdata = alloc_n_copy(s, s + strlen(s) + 1);      // 分配 strlen(s) + 1 个内存单元，最后一个用来存放空字符 '\0'
        elements = newdata.first;
        end = newdata.second;
    }
    String(const String& s)
    {
		std::cout << "String::CopyConstructor" << std::endl;
		auto newdata = alloc_n_copy(s.elements, s.end);
        elements = newdata.first;
        end = newdata.second;
    }
	String(String &&s) noexcept 
		: elements(s.elements), end(s.end)
	{
		std::cout << "String::MoveConstructor" << std::endl;
		// 令 s 进入这样的状态——对其运行析构函数是安全的
		s.elements = s.end = nullptr;
	}
    String& operator= (const String& rhs)
    {
        auto newdata = alloc_n_copy(rhs.elements, rhs.end);
        free();
        elements = newdata.first;
        end = newdata.second;
        return *this;
    }
	String& operator= (String&& rhs) noexcept
	{
		if (this != &rhs)
		{
			free();
			elements = rhs.elements;
			end = rhs.end;
			// 令 s 进入这样的状态——对其运行析构函数是安全的
			rhs.elements = rhs.end = nullptr;
		}
		return *this;
	}
    ~String()
    {
        free();
    }

    const char* c_str() const { return elements; }
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

#include <iostream>
#include <vector>
#include <utility>
#include "String.h"

using namespace std;

int main()
{
	String str("Hello");
	String str2("World");

	String str3 = std::move(str);


	return 0;
}


String::MoveConstructor
请按任意键继续. . .

*/
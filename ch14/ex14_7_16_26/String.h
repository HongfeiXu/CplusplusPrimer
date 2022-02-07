#pragma once

/*

练习 13.44：编写标准函数库 string 类的简化版本，命名为 String。你的类应该至少有一个默认构造函数和一个接受 C 风格字符串指针参数的构造函数。
使用 allocator 为你的 String 类分配所需内存

练习 13.47：对你在练习 13.44 中定义的 String 类，为它的拷贝构造函数拷贝赋值运算符添加一条语句，在每次函数执行时打印一条信息。

练习 13.48：定义一个 vector<String> 并在其上多次调用 push_back。运行你的程序，并观察 String 被拷贝了多少次。

练习 13.50：在你的 String 类的移动操作中添加打印语句，并重新运行13.6.1节的练习13.48中的程序，它使用了一个vector，观察什么时候会避免拷贝。

练习14.7：你在13.5节的练习中曾经编写了一个String类，为它定义一个输出运算符。

练习14.16：为你的 StrBlob 类、StrBlobPtr 类、StrVec 类和 String 类分别定义相等运算符和不相等运算符。

练习14.18：为你的 StrBlob 类、StrBlobPtr 类、StrVec 类和 String 类分别定义关系运算符。

*/

#include <memory>
#include <cstring>      // strlen()
#include <utility>		// move
#include <iostream>
#include <iterator>
#include <algorithm>

class String {
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	friend bool operator<(const String&, const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator<=(const String&, const String&);
	friend bool operator>=(const String&, const String&);
public:
	String() : String("") { }       // 默认构造字符串时，字符串占一个内存单元，存储 '\0'
	String(const char* s)
	{
		std::cout << "String::Constructor" << std::endl;
		auto newdata = alloc_n_copy(s, s + strlen(s) + 1);      // 分配 strlen(s) + 1 个内存单元，最后一个用来存放空字符 '\0'
		elements = newdata.first;
		end_elem = newdata.second;
	}
	String(const String& s)
	{
		std::cout << "String::CopyConstructor" << std::endl;
		auto newdata = alloc_n_copy(s.elements, s.end_elem);
		elements = newdata.first;
		end_elem = newdata.second;
	}
	String(String&& s) noexcept
		: elements(s.elements), end_elem(s.end_elem)
	{
		std::cout << "String::MoveConstructor" << std::endl;
		// 令 s 进入这样的状态——对其运行析构函数是安全的
		s.elements = s.end_elem = nullptr;
	}
	String& operator= (const String& rhs)
	{
		auto newdata = alloc_n_copy(rhs.elements, rhs.end_elem);
		free();
		elements = newdata.first;
		end_elem = newdata.second;
		return *this;
	}
	String& operator= (String&& rhs) noexcept
	{
		if (this != &rhs)
		{
			free();
			elements = rhs.elements;
			end_elem = rhs.end_elem;
			// 令 s 进入这样的状态——对其运行析构函数是安全的
			rhs.elements = rhs.end_elem = nullptr;
		}
		return *this;
	}
	char& operator[] (std::size_t n)
	{
		return elements[n];
	}
	const char& operator[] (std::size_t n) const
	{
		return elements[n];
	}
	~String()
	{
		free();
	}

	char* begin() const { return elements; }
	char* end() const { return end_elem; }

	const char* c_str() const { return elements; }
	size_t size() const { return end_elem - elements; }
	size_t length() const { return end_elem - elements - 1; }    // 最后一个位置用来存放空字符 '\0'
private:
	std::pair<char*, char*> alloc_n_copy(const char* b, const char* e)
	{
		auto data = alloc.allocate(e - b);
		return { data, std::uninitialized_copy(b, e, data) };
	}
	void free()
	{
		if (elements)
		{
			std::for_each(elements, end_elem, [this](char& c) { alloc.destroy(&c); });
			alloc.deallocate(elements, end_elem - elements);
		}
	}

private:
	char* elements;
	char* end_elem;
	std::allocator<char> alloc;     // 分配元素
};

std::ostream& operator<<(std::ostream& out, const String& s);
bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
bool operator<(const String&, const String&);
bool operator>(const String&, const String&);
bool operator<=(const String&, const String&);
bool operator>=(const String&, const String&);

void test_string();

#pragma once

#include <string>
#include <iostream>
#include <cstdarg>
using namespace std;

// 1. 可变参数initializer_list
// 局限性较大，列表里只能同类型，比vector更轻量，元素是常量

/// <summary>
/// 输出错误信息的函数，可以作用于可变数量的实参
/// </summary>
void error_msg(initializer_list<string> il)
{
	for (const auto &item : il)
		cout << item << " ";
	cout << endl;
}

// 2. 省略符形参
// https://en.cppreference.com/w/cpp/utility/variadic/va_start

/// <summary>
/// 求和
/// 缺点：每次调用要先把求和个数输进来
/// </summary>
/// <param name="count">后面要求和的参数个数</param>
/// <param name=""></param>
/// <returns></returns>
int sum(int count, ...)
{
	if (count <= 0)
		return 0;
	int result = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i)
	{
		result += va_arg(args, int);
	}
	va_end(args);
	return result;
}


// 3. 模板可变参数

template<typename T, typename... Args>
void foo(const T& t, const Args&... rest)
{
	cout << sizeof(t) << endl;
	cout << sizeof...(Args) << endl;	// 打印可变参数数量
	cout << sizeof...(rest) << endl;	// 打印可变参数数量
}

/// <summary>
/// 递归的打印出参数
/// TODO: 有没有更好的方式了？？？
/// </summary>
/// <typeparam name="T"></typeparam>
/// <typeparam name="...Args"></typeparam>
/// <param name="os"></param>
/// <param name="t"></param>
/// <returns></returns>
template<typename T, typename... Args>
ostream& print(ostream& os, const T& t)
{
	return os << t << ", ";
}

template<typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest)
{
	os << t << ", ";
	return print(os, rest...);
}


// 4. 宏

#define debug(...) print(cout, __VA_ARGS__)	// __VA_ARGS__ 就是可变参数列表



void test()
{
	// 向initializer_list形参中传递一个值的序列，则必须把序列放在一堆花括号呢
	error_msg({ "debug", "xhf", "something bad is happening" });

	// 第一个参数是待求和的变量的个数
	cout << sum(5, 1, 2, 3, 4, 5) << endl;

	// 模板可变参数示例
	foo(10, "hello", "world", 123);

	// 直接用模板函数
	print(cout, 1, 2, "hello", "world");
	cout << endl;

	// 封装了一个宏
	debug("this", "is", 102);
	cout << endl;
}

/*

debug xhf something bad is happening
15
4
3
3
1, 2, hello, world,
this, is, 102,

*/




#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 类型模板参数
template <typename T>
int compare(const T& v1, const T& v2)
{
	if (v1 < v2)
		return -1;
	if (v2 < v1)
		return 1;
	return 0;
}

// 非类型模板参数
template<unsigned N, unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M])		// // 传入的必须是常量表达式
{
	cout << N << " " << M << endl;	// 编译期推断出 N 和 M 的值
	return strcmp(p1, p2);
}

// 基于非类型模板参数的应用

/// <summary>
/// 打印数组内容
/// 可处理任意大小、元素类型的数组
/// </summary>
template<typename T, unsigned N>
void print(const T(&arr)[N])	// 数组引用形参
{
	copy(std::cbegin(arr), std::cend(arr), ostream_iterator<T>(cout, " "));
}

/// <summary>
/// 返回给定数组大小，返回的是常量表达式（编译期就能得到结果）
/// </summary>
template <typename T, unsigned N>
constexpr unsigned getArraySize(const T(&arr)[N])
{
	return N;
}


void test()
{
	float fa = 1.2f;
	float fb = 1.3f;
	cout << compare(fa, fb) << endl;

	cout << compare("hi", "mom") << endl;	// 传入的必须是常量表达式

	int arr[] = { 1,2,3,4,5,6 };
	print(arr);
	cout << endl;

	cout << getArraySize(arr) << endl;
	
	// 只有当 getArraySize 返回常量表达式时，这里才是对的；
	// 否则报错：“对未定义的函数或为未声明为“constexpr”的函数的调用导致了故障”
	int arrb[getArraySize(arr)];
}

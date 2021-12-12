#pragma once

#include <string>
#include <iostream>
#include <cstdarg>
using namespace std;

// 1. �ɱ����initializer_list
// �����Խϴ��б���ֻ��ͬ���ͣ���vector��������Ԫ���ǳ���

/// <summary>
/// ���������Ϣ�ĺ��������������ڿɱ�������ʵ��
/// </summary>
void error_msg(initializer_list<string> il)
{
	for (const auto &item : il)
		cout << item << " ";
	cout << endl;
}

// 2. ʡ�Է��β�
// https://en.cppreference.com/w/cpp/utility/variadic/va_start

/// <summary>
/// ���
/// ȱ�㣺ÿ�ε���Ҫ�Ȱ���͸��������
/// </summary>
/// <param name="count">����Ҫ��͵Ĳ�������</param>
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


// 3. ģ��ɱ����

template<typename T, typename... Args>
void foo(const T& t, const Args&... rest)
{
	cout << sizeof(t) << endl;
	cout << sizeof...(Args) << endl;	// ��ӡ�ɱ��������
	cout << sizeof...(rest) << endl;	// ��ӡ�ɱ��������
}

/// <summary>
/// �ݹ�Ĵ�ӡ������
/// TODO: ��û�и��õķ�ʽ�ˣ�����
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


// 4. ��

#define debug(...) print(cout, __VA_ARGS__)	// __VA_ARGS__ ���ǿɱ�����б�



void test()
{
	// ��initializer_list�β��д���һ��ֵ�����У����������з���һ�ѻ�������
	error_msg({ "debug", "xhf", "something bad is happening" });

	// ��һ�������Ǵ���͵ı����ĸ���
	cout << sum(5, 1, 2, 3, 4, 5) << endl;

	// ģ��ɱ����ʾ��
	foo(10, "hello", "world", 123);

	// ֱ����ģ�庯��
	print(cout, 1, 2, "hello", "world");
	cout << endl;

	// ��װ��һ����
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




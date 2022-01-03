#pragma once

/*

16.4 可变参数模板

*/


#include <iostream>
#include <sstream>
#include <string>
#include "tempate_overload.h"

using namespace std;

template<typename T>
ostream& print_util(ostream& os, const T& t)
{
	return os << t;
}

template<typename T, typename... Args>
ostream& print_util(ostream& os, const T& t, const Args&... rest)	// 扩展Args，生成函数参数列表
{
	os << t << ", ";
	return print_util(os, rest...);	// 扩展rest，生成实参列表
}


template<typename... Args>
ostream& errorMsg(ostream& os, const Args... rest)
{
	// print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an))
	return print_util(os, debug_rep(rest)...);
}


void test()
{
	print_util(cout, 1, 2.0, 3, "hello", "world") << endl;
}
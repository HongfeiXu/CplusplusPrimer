#pragma once

/*

16.3 重载与模板

*/

#include <string>
#include <sstream>

using namespace std;


template<typename T>
string debug_rep(const T& t)
{
	ostringstream ret;
	ret << t;
	return ret.str();
}

template<typename T>
string debug_rep(T* p)
{
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << "null pointer";
	return ret.str();
}

string debug_rep(const string& s)
{
	return '"' + s + '"';
}

// 希望字符指针按string进行处理，则定义如下两个非模板重载版本
string debug_rep(char* p)
{
	return debug_rep(string(p));
}

string debug_rep(const char* p)
{
	return debug_rep(string(p));
}

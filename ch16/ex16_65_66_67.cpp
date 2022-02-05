/*

练习16.65
在16.3节中我们定义了两个重载的 debug_rep 版本，一个接受 const char* 参数，另一个接受 char * 参数。将这两个函数重写为特例化版本。

练习16.66
重载debug_rep 函数与特例化它相比，有何优点和缺点？

会改变函数匹配顺序，几个函数都提供同样好的匹配的情况下，编译器会选择非模板版本。

练习16.67
定义特例化版本会影响 debug_rep 的函数匹配吗？如果不影响，为什么？

不会改变，特例化模板函数不会重载函数，不会影响函数匹配顺序。
*/

#include <string>
#include <sstream>
#include <iostream>

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

template<>
string debug_rep(char* p)
{
	return debug_rep(string(p));
}

template<>
string debug_rep(const char* p)
{
	return debug_rep(string(p));
}

int main()
{
	std::cout << debug_rep("hello") << std::endl;

	return 0;
}
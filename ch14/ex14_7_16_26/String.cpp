#include "String.h"
#include <algorithm>	// std::equal


std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << s.c_str();
	return out;
}

bool operator==(const String& lhs, const String& rhs)
{
	return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator!=(const String& lhs , const String& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const String& lhs, const String& rhs)
{
	return rhs < lhs;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const String& lhs, const String& rhs)
{
	return !(lhs < rhs);
}

void test_string()
{
	String str("Hello");
	std::cout << str << std::endl;

	String str1("fuck");
	String str2("hel");
	std::cout << (str1 == str2) << std::endl;
	std::cout << (str1 < str2) << std::endl;
	std::cout << (str1 >= str2) << std::endl;
	std::cout << str1[1] << std::endl;
	str1[1] = 'c';
	std::cout << str1 << std::endl;
}

/*
String::Constructor
Hello

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 46736)已退出，代码为 0。
按任意键关闭此窗口. . .
*/
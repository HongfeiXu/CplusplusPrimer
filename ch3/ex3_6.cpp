/*
* 练习3.6：编写一段程序，使用范围for语句将字符串内的所有字符用X代替。

*/

#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main ()
{
	string str ("Hello World!!!");
	for (auto &c : str)		// 如果想要改变string对象中字符的值，必须把循环变量定义为引用类型。
	{
		c = 'X';
	}
	cout << str << endl;
	
	return 0;
}

/*

XXXXXXXXXXXXXX
请按任意键继续. . .

*/
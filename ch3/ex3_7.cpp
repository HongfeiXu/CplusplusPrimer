/*
* 练习3.7：就上一题完成的程序而言，如果将控制循环变量的类型设为char将发生什么？

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
	for (char c : str)		
	{
		c = 'X';
	}
	cout << str << endl;
	
	return 0;
}

/*

Hello World!!!
请按任意键继续. . .

The point here is using reference to mutate a string. 
If changed to something like below, c would become a char rather than char&. 
In such case, c is a copy of each character of string str, 
thus the assignment c = 'X' won't mutate str. As a result, after this for range statement, nothing changes.

*/
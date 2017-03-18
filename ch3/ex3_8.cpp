/*
* 练习3.8：分别用while循环和传统的for循环重写第一题的程序，你觉得哪种形式更好呢？
* 更喜欢 range for
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
	cout << str << endl;
	// while
	string::size_type index = 0;
	while (index < str.size ())
		str[index++] = 'X';
	cout << str << endl;
	// for
	for (index = 0; index < str.size (); index++)
		str[index] = 'Y';
	cout << str << endl;
	// range for
	for (auto &c : str)		
		c = 'Z';
	cout << str << endl;
	
	return 0;
}

/*

Hello World!!!
XXXXXXXXXXXXXX
YYYYYYYYYYYYYY
ZZZZZZZZZZZZZZ
请按任意键继续. . .

*/
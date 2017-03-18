/*
* 练习3.10：编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。
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
	string str ("Hello----------- World!!!");
	for (auto c : str)
	{
		if (!ispunct (c))
			cout << c;
	}
	cout << endl;
	
	return 0;
}

/*

Hello World
请按任意键继续. . .

*/
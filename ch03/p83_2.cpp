/*
* P83 使用 range for 语句改变字符串中的字符。（此处为将字符串改写为大写字母的形式）
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
	string str ("Hello world!!!");
	for (auto &c : str)
	{
		c = toupper (c);
	}
	cout << str << endl;

	return 0;
}

/*
HELLO WORLD!!!
请按任意键继续. . .


*/
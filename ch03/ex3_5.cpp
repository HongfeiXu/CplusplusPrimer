/*
* 练习3.3：编写一段程序从标准输入中读入多个字符串并将它们连接在一起，输出连接成的大字符串。
* 改写上述程序，用空格把输入的多个字符串分隔开来。
*/

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;


int main ()
{
	string str;
	cin >> str;
	string temp;
	while (cin >> temp)
	{
		// 多个字符串并将它们连接在一起
		//str += temp;
		// 用空格把输入的多个字符串分隔开来。
		str += (" " + temp);
	}
	cout << str << endl;

	return 0;
}

/*


hello
world
haha
^Z
helloworldhaha
请按任意键继续. . .


hello
world
haha
^Z
hello world haha
请按任意键继续. . .



*/
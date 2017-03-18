/*
* 练习3.22：修改之前那个输出text第一段的程序，首先把text的第一段全部改成大写形式，然后在输出它。
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main ()
{
	vector<string> text;
	// 输入每一行
	string line;
	while (getline (cin, line))
		text.push_back (line);
	// 用迭代器的方式处理
	for (auto it = text.begin (); it != text.end () && !it->empty(); ++it)		// it为vector<string>::iterator

	{
		for (auto it2 = it->begin (); it2 != it->end (); ++it2)							// it2为string::iterator
		{
			*it2 = toupper (*it2);
		}
	// 也可用这种方式来将字符串改为大写。
	//	for (auto &c : *it)
	//		if (islower (c))
	//			c = toupper (c);

		cout << *it << endl;
	}

	return 0;
}

/*

Hello world whate
HI whate areyou

dasj fklas
^Z
HELLO WORLD WHATE
HI WHATE AREYOU
请按任意键继续. . .

*/
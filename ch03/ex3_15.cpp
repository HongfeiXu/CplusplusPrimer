/*
* 练习3.15：编写一段程序，用cin读入一组字符串并把它们存入一个vector对象。
*/

#include <iostream>
#include <string>	// 使用标准库类型string
#include <vector> // 使用标准库类型vector

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main ()
{
	vector<string> v;
	string temp;
	while (cin >> temp)
	{
		v.push_back (temp);
	}
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}

/*

hello world
^Z
hello world
请按任意键继续. . .

*/
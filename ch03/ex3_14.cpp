/*
* 练习3.14：编写一段程序，用cin读入一组整数并把它们存入一个vector对象。
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
	vector<int> vint;
	int temp;
	while (cin >> temp)
	{
		vint.push_back (temp);
	}
	for (auto i : vint)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}

/*

1 2 3 4 5
^Z
1 2 3 4 5
请按任意键继续. . .

*/
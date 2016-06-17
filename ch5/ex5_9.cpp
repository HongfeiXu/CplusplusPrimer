/*
* 练习5.9：编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音字母。
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;


int main ()
{
	char ch;
	int vowelCnt = 0;
	while (cin >> ch)
	{
		if (ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u')
			++vowelCnt;
	}
	cout << vowelCnt << endl;

	return 0;
}

/*

hello world
^Z
3
请按任意键继续. . .

*/
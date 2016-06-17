/*
* 练习5.10：编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音字母。也统计大写形式。
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main ()
{
	char ch;
	int vowelCnt = 0;
	while (cin >> ch)
	{
		if (ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'A' || ch == 'O' || ch =='E' || ch == 'I' || ch == 'U')
			++vowelCnt;
	}
	cout << vowelCnt << endl;

	return 0;
}

/*

Hello World! What Are You Doing?
^Z
10
请按任意键继续. . .

*/
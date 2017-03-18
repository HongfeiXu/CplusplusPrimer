/*
* 练习3.1：使用恰当的using声明重做1.4.1节和2.6.2节的练习。
* 练习1.10：编写程序，提示用户输入两个整数，打印出这两个整数所指定范围内的所有整数。
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main ()
{
	int a, b;
	cin >> a >> b;
	if (a <= b)
	{
		for (int i = a; i <= b; i++)
		{
			cout << i << endl;
		}
	}
	else
	{
		for (int i = b; i <= a; i++)
		{
			cout << i << endl;
		}
	}

	return 0;
}

/*

19 2
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
请按任意键继续. . .

*/
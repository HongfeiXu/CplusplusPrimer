/*
* 练习3.1：使用恰当的using声明重做1.4.1节和2.6.2节的练习。
* 练习1.10：编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。
*/

#include <iostream>

using std::cout;
using std::endl;

int main ()
{
	for (int i = 10; i >= 0; i--)
	{
		cout << i << endl;
	}

	return 0;
}

/*

10
9
8
7
6
5
4
3
2
1
0
请按任意键继续. . . .

*/
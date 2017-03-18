/*
* 练习3.1：使用恰当的using声明重做1.4.1节和2.6.2节的练习。
* 练习1.9：编写程序，使用while循环将50到100的整数相加。
*/

#include <iostream>

using std::cout;
using std::endl;

int main ()
{
	int sum = 0;
	for (int i = 50; i <= 100; i++)
		sum += i;
	cout << sum << endl;

	return 0;
}

/*

3825
请按任意键继续. . .

*/
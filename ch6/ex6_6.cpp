/*
* 练习6.6：说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。
* 函数printStars传入参数 numOfStars，输出 numOfStars 个星号，并使用静态局部变量 ctr 统计自己是第几次输出。
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printStars (unsigned numOfStars)
{
	static size_t ctr = 0;
	cout << "Line " << ++ctr << ": ";
	for (unsigned i = 0; i != numOfStars; ++i)
	{
		cout << "*";
	}
	cout << endl;
}

int main ()
{
	printStars (3);
	printStars (10);
	printStars (5);

	return 0;
}

/*

Line 1: ***
Line 2: **********
Line 3: *****
请按任意键继续. . .

*/
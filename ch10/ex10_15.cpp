/*
*	练习 10.15：编写一个lamdba，捕获它所在函数的 int，并接受一个 int 参数。
*	lamdba 应该返回捕获的 int 和 int 参数的和。
*/
#include <iostream>

using namespace std;


int main()
{
	int a = 12;

	auto lamdba1 = [a] (int b) { return a + b; };

	cout <<	lamdba1(11) << endl;

	return 0;
}

/*

23
请按任意键继续. . .

*/
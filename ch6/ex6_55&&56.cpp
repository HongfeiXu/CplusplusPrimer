/*
* 练习6.54：编写函数的声明，令其接受两个 int 形参并且返回类型也是 int；
* 然后声明一个 vector 对象，令其元素时指向该函数的指针。
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int add (int a, int b)
{
	return a + b;
}

int subtract (int a, int b)
{
	return a - b;
}

int multiply (int a, int b)
{
	return a * b;
}

int divide (int a, int b)
{
	return b != 0 ? a / b : 0;
}

using pf = int (*) (int, int);

int main ()
{
	vector<pf> vf{add, subtract, multiply, divide};

	for (auto f : vf)
	{
		cout << f (2, 2) << endl;
	}

	return 0;
}

/*

4
0
4
1
请按任意键继续. . .

*/
/*
* 练习6.47：改写p205练习中使用递归输出vector内容的程序，使其有条件的输出与执行过程有关的信息。
* 例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void f ()
{
	cout << "f()" << endl;
}

void f (int a)
{
	cout << "f(int)" << endl;
}

void f (int a, int b)
{
	cout << "f(int, int)" << endl;
}

void f (double a, double b = 3.14)
{
	cout << "f(double , double = 3.14)" << endl;
}

int main ()
{
//	f (2.56, 42);		// 2 个重载有相似的转换
	f (42);
	f (42, 0);
	f (2.56, 3.14);

	return 0;
}

/*

f(int)
f(int, int)
f(double , double = 3.14
请按任意键继续. . .

*/
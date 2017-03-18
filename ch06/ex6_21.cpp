/*
* 练习6.21：编写一个函数，令其接收两个参数：一个是int类型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大的那个。
* 该函数中指针的类型应该是什么？
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int getBigger (int a, const int *b)
{
	if (a >= *b)
		return a;
	else
		return *b;
}

int main ()
{
	int a = 0, b = 0;
	while (cin >> a >> b)
		cout << "The bigger one is " << getBigger (a, &b) << endl;


	return 0;
}


/*

3 4
The bigger one is 4
10 9
The bigger one is 10
^Z
请按任意键继续. . .

*/
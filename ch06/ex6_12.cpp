/*
* 练习6.12：修改练习6.10的程序，使用引用而非指针交换两个整数的值。
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap (int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main ()
{
	int a = 3, b = 4;
	cout << a << " " << b << endl;
	swap (a, b);
	cout << a << " " << b << endl;
	  
	return 0;
}
 

/*

3 4
4 3
请按任意键继续. . .

*/
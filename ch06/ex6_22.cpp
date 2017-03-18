/*
* 练习6.22：编写一个函数，令其交换两个int指针。
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swapIntPointer (int *&a, int *&b)		// a 是 int *类型变量的引用
{
	int *temp;
	temp = a;
	a = b;
	b = temp;
}

int main ()
{
	int a = 3, b = 4;
	int *pa = &a, *pb = &b;
	cout << *pa << " " << *pb << endl;
	swapIntPointer (pa, pb);
	cout << *pa << " " << *pb << endl;

	return 0;
}


/*

3 4
4 3
请按任意键继续. . .

*/
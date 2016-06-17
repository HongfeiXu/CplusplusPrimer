/*
* 练习6.10：编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出转换后的结果，以此验证函数的正确性。
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main ()
{
	int a = 3, b = 2;
	cout << a << " " << b << endl;
	swap (&a, &b);
	cout << a << " " << b << endl;

	return 0;
}
 

/*

3 2
2 3
请按任意键继续. . .

*/
/*
* 练习3.31：编写一段程序，定义一个含有10个int的数组，令每个元素的值都是其下标值。
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main ()
{
	int array[10];
	for (size_t i = 0; i < 10; i++)
		array[i] = i;
	for (size_t i = 0; i < 10; i++)
		cout << array[i] << " ";
	cout << endl;
		
	return 0;
}

/*

0 1 2 3 4 5 6 7 8 9
请按任意键继续. . .

*/
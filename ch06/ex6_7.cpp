/*
* 练习6.7 ： 编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1.
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

size_t count_calls ()
{
	static size_t ctr = 0;
	return ctr++;
}

int main ()
{
	for (size_t i = 0; i != 10; i++)
		cout << count_calls () << endl;

	return 0;
}

/*

0
1
2
3
4
5
6
7
8
9
请按任意键继续. . .

*/
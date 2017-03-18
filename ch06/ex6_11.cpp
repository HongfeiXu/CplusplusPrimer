/*
* 练习6.11：编写并验证你自己的reset函数，使其作用于引用类型的参数。
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void reset (int &i)
{
	i = 0;
}

int main ()
{
	int i = 10;
	reset (i);
	cout << i << endl;
	  
	return 0;
}
 

/*

0
请按任意键继续. . .

*/
/*
* 练习4.7：溢出是何含义？写出三条将导致溢出的表达式。
* 当计算结果超出该类型所能表示的范围时就会产生溢出。
*/

#include <iostream>
#include <cstring>

using std::cout; 
using std::endl;


int main ()
{
//	cout << sizeof (short) << endl;
	short svalue = 32767;		// 本机器上short类型占16位
	cout << ++svalue << endl;
	unsigned uivalue = 0;
	cout << --uivalue << endl;
	unsigned short usvalue = 65535;
	cout << ++usvalue << endl;

	return 0;
}

/*

-32768
4294967295
0
请按任意键继续. . .

*/
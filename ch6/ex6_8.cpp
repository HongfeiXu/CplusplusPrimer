/*
* 练习6.8：编写一个名为Chapter6.h的头文件，令其包含6.1节练习中的函数声明。
*/

// 文件Chapter.h内容
#ifndef CHAPTER_6_H
#define CHAPTER_6_H

int fact (int val);
int askuser ();


#endif // !CHAPTER_6_H

// 文件main.c中的内容

#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;


int main ()
{
	int val = askuser ();
	cout << fact (val) << endl;

	return 0;
}

int fact (int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}

int askuser ()
{
	int val;
	cout << "Please enter a number: ";
	cin >> val;
	return val;
}


/*

Please enter a number: 5
120
请按任意键继续. . .

*/
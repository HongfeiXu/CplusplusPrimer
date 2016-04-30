/*
练习1.4：我们的程序使用加法运算符+来将两个数相加。
编写程序使用乘法运算符*，来打印两个数的积。
*/

#include <iostream>

int main ()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The product of " << v1 << " and " << v2
		<< " is " << v1 * v2 << std::endl;


	return 0;
}

/*

F:\CplusplusPrimerCode\ch01>cl /EHsc /W4 ex1_4.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

ex1_4.cpp
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:ex1_4.exe
ex1_4.obj

F:\CplusplusPrimerCode\ch01>ex1_4
Enter two numbers:
3 9
The product of 3 and 9 is 27

F:\CplusplusPrimerCode\ch01>

*/
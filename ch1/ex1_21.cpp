/*
* 练习1.21：编写程序，读取两个ISBN相同的Sales_item对象，输出它们的和。
*/

#include <iostream>
#include "Sales_item.h"

int main ()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	std::cout << item1 + item2 << std::endl;

	return 0;
}

/*

文件add_item内容
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00 

F:\CplusplusPrimer\ch1>cl /EHsc /W4 ex1_21.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

ex1_21.cpp
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:ex1_21.exe
ex1_21.obj

F:\CplusplusPrimer\ch1>ex1_21 < data\add_item
0-201-78345-X 5 110 22

F:\CplusplusPrimer\ch1>

*/
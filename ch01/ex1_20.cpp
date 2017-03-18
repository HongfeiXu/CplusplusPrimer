/*
* 练习1.20：读取一组书籍销售记录，将每条记录打印到标准输出上
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item book;
	while (std::cin >> book)
	{
		std::cout << book << std::endl;
	}
	
	return 0;
}

/*

F:\CplusplusPrimer\ch1>cl /EHsc /W4 ex1_20.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

ex1_20.cpp
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:ex1_20.exe
ex1_20.obj

F:\CplusplusPrimer\ch1>ex1_20 < data\book_sales
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 2 30 15
0-201-88954-4 5 60 12
0-201-88954-4 7 84 12
0-201-88954-4 2 24 12
0-399-82477-1 2 90.78 45.39
0-399-82477-1 3 136.17 45.39
0-201-78345-X 3 60 20
0-201-78345-X 2 50 25

F:\CplusplusPrimer\ch1>

*/
/*
* 练习1.23：编写程序，读取多条销售记录，并统计每个ISBN（每本书）有几条销售记录。
*/

#include <iostream>
#include "Sales_item.h"

int main ()
{
	Sales_item item1, item2;
	if (std::cin >> item1)
	{
		int cnt = 1;
		while (std::cin >> item2)
		{
			if (item1.isbn() == item2.isbn())
			{
				++cnt;
			}
			else
			{
				std::cout << item1 << " occurs " << cnt << " times." << std::endl;
				cnt = 1;
				item1 = item2;
			}
		}
		std::cout << item1 << " occurs " << cnt << " times." << std::endl;
	}
	else
	{
		std::cerr << "No data." << std::endl;
		return -1;
	}

	return 0;
}

/*

文件book_sales内容：

0-201-70353-X 4 24.99
0-201-82470-1 4 45.39
0-201-88954-4 2 15.00 
0-201-88954-4 5 12.00 
0-201-88954-4 7 12.00 
0-201-88954-4 2 12.00 
0-399-82477-1 2 45.39
0-399-82477-1 3 45.39
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00



F:\CplusplusPrimer\ch1>cl /EHsc /W4 ex1_23.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

ex1_23.cpp
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:ex1_23.exe
ex1_23.obj

F:\CplusplusPrimer\ch1>ex1_23 < data\book_sales
0-201-70353-X 4 99.96 24.99 occurs 1 times.
0-201-82470-1 4 181.56 45.39 occurs 1 times.
0-201-88954-4 2 30 15 occurs 4 times.
0-399-82477-1 2 90.78 45.39 occurs 2 times.
0-201-78345-X 3 60 20 occurs 2 times.

F:\CplusplusPrimer\ch1>

*/
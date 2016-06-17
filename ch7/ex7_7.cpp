/*
* 练习7.7：使用这些新函数重写7.1.2节练习7.3中的交易处理程序。
*/

#include "ex7_06.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main ()
{
	Sales_data total;
	if (read(cin, total))
	{
		Sales_data trans;
		while (read(cin, trans))
		{
			if (total.isbn () == trans.isbn ())
				total.combine (trans);
			else
			{
				print (cout, total) << endl;	// 因为 print 的返回值为 cout
				total = trans;
			}
		}
		print (cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/*

I:\vs\cplusplus\cplusplus>cl /EHsc /W4 main.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

main.cpp
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj

I:\vs\cplusplus\cplusplus>main < book_sales
0-201-70353-X 4 99.96
0-201-82470-1 4 181.56
0-201-88954-4 16 198
0-399-82477-1 5 226.95
0-201-78345-X 5 110

I:\vs\cplusplus\cplusplus>
*/
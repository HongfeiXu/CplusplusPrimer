/*
* 练习7.1：使用2.6.1节练习定义的Sales_data类为1.6节（第21页）的交易处理过程编写一个新版本。
*/

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main ()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	{
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if (total.bookNo == trans.bookNo)
			{
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else
			{
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
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
0-201-70353-X 4 24.99
0-201-82470-1 4 45.39
0-201-88954-4 16 51
0-399-82477-1 5 90.78
0-201-78345-X 5 45

*/
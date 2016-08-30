/*
* 练习 8.7：修改上一节的程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给main函数。
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Sales_data {

	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	double avg_price() const
	{
		if(units_sold)
		{
			return revenue / units_sold;
		}
		else
			return 0.0;
	}

	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


istream &read(istream &is, Sales_data &item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

int main(int argc, char *argv[])
{
	ifstream input(argv[1]);		// 打开销售记录文件
	ofstream output(argv[2]);		// 打开输出文件
	Sales_data total;
	if(read(input, total))			// 用 fstream 代替 iostream&
	{
		Sales_data trans;
		while(read(input, trans))
		{
			if(total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}

	return 0;
}

/*

I:\vs\cplusplus\cplusplus>cl /EHsc /W4 main.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24210 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

main.cpp
main.cpp(48): warning C4100: 'argc': unreferenced formal parameter
Microsoft (R) Incremental Linker Version 14.00.24210.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj

I:\vs\cplusplus\cplusplus>main book_sales result.txt

result.txt的内容：

0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22


*/


/*

int main()
{
Sales_data total;
if(read(cin, total))
{
Sales_data trans;
while(read(cin, trans))
{
if(total.isbn() == trans.isbn())
total.combine(trans);
else
{
print(cout, total) << endl;	// 因为 print 的返回值为 cout
total = trans;
}
}
print(cout, total) << endl;
}
else
{
cerr << "No data?!" << endl;
return EXIT_FAILURE;
}
return EXIT_SUCCESS;
}


I:\vs\cplusplus\cplusplus>cl /EHsc /W4 main.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24210 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

main.cpp
Microsoft (R) Incremental Linker Version 14.00.24210.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj

I:\vs\cplusplus\cplusplus>main < book_sales
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22



*/



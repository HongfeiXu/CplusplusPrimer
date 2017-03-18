/*
1.23 编写程序，读取多条销售记录，并统计每个ISBN（每本书）有几条销售记录
*/
#include <iostream>
#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main ()
{
	Sales_data val, currval;
	double price = 0.0;
	if (std::cin >> currval.bookNo >> currval.units_sold >> price)
	{
		int cnt = 1;
		while (std::cin >> val.bookNo >> val.units_sold >> price)
		{
			if (val.bookNo == currval.bookNo)
				cnt++;
			else
			{
				std::cout << currval.bookNo << " " << cnt << " sale records." << std::endl;
				currval.bookNo = val.bookNo;
				cnt = 1;
			}
		}
		std::cout << currval.bookNo << " " << cnt << " sale records." << std::endl;
	}

	return 0;
}



/*

book_sales

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

I:\vs\learnCplus\learnCplus>main < book_sales
0-201-70353-X 1 sale records.
0-201-82470-1 1 sale records.
0-201-88954-4 4 sale records.
0-399-82477-1 2 sale records.
0-201-78345-X 2 sale records.

I:\vs\learnCplus\learnCplus>
*/
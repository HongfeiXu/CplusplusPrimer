/*
* 练习1.22：编写程序，读取多个具有相同ISBN的销售记录，输出所有记录的和。
*/

#include <iostream>
#include "Sales_item.h"

int main ()
{
	Sales_item total;
	if (std::cin >> total)
	{
		Sales_item temp;
		while (std::cin >> temp)
		{
			if (total.isbn() == temp.isbn())
			{
				total += temp;
			}
			else
			{
				std::cout << total << std::endl;
				total = temp;
			}
		}
		std::cout << total << std::endl;
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



F:\CplusplusPrimer\ch1>ex1_22 < data\book_sales
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22

F:\CplusplusPrimer\ch1>

*/
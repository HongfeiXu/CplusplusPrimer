/*
1.22 ��д���򣬶�ȡ���������ͬISBN�����ۼ�¼��������м�¼�ĺ͡�
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
	Sales_data temp, total;
	double price = 0.0;

	while (std::cin >> temp.bookNo >> temp.units_sold >> price)
	{
		total.units_sold += temp.units_sold;
		total.revenue += temp.units_sold * price;
	}
	total.bookNo = temp.bookNo;
	std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;

	return 0;
}
/*
* 练习 8.8：修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。
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
	ofstream output(argv[2], ofstream::app);
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

运行两次的结果：
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22


*/


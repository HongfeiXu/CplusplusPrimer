#include "Sales_data.h"

// 成员函数
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

bool Sales_data::operator==(const Sales_data& rhs) const
{
	return (bookNo == rhs.bookNo) && (units_sold == rhs.units_sold) && (revenue == rhs.revenue);
}

// 非成员函数，但是是接口函数
ostream &operator<<(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

istream &operator>>(istream &is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)	// 检查输入是否成功
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();	// 输入失败：对象被赋予默认的状态
	return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

size_t std::hash<Sales_data>::operator()(const Sales_data& s) const
{
	return hash<string>{}(s.bookNo) ^
		hash<unsigned>{}(s.units_sold) ^
		hash<double>{}(s.revenue);
}

void test_sales_data()
{
	Sales_data s1{ "book", 10, 100 };
	Sales_data s2{ "phone", 1, 1000 };
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	auto s3 = s1 + s2;
	std::cout << s3 << std::endl;

	Sales_data s4;
	std::cin >> s4;
	std::cout << s4 << std::endl;
}

/*

book 10 1000 100
phone 1 1000 1000
book 11 2000 181.818
computer 1 10000
computer 1 10000 10000

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 62636)已退出，代码为 0。
按任意键关闭此窗口. . .

*/

#include "ex7_26.h"

// 成员函数
Sales_data& Sales_data::combine (const Sales_data & rhs)
{
	units_sold += rhs.units_sold;		// 把 rhs 的成员加到 this 对象的成员上
	revenue += rhs.revenue;
	return *this;					// 返回调用该函数的对象
}

// 非成员函数，但是是接口函数
istream &read (istream &is, Sales_data &item)		// IO 类属于不能被拷贝的类型，因此只能用引用来传递它们。
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print (ostream &os, const Sales_data &item)
{
	os << item.isbn () << " " << item.units_sold << " "
		<< item.revenue;
	return os;
}

Sales_data add (const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine (rhs);		// 把 rhs 的数据成员加到 sum 当中。
	return sum;
}

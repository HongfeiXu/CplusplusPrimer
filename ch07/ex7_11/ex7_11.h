/*
* 练习7.6：对于函数 add、read 和 print，定义你自己的版本。
*/

#ifndef EX7_11_H
#define EX7_11_H

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

struct Sales_data {
	// 新增的构造函数
	Sales_data () = default;
	Sales_data (const string &s) : bookNo(s) { }
	Sales_data (const string &s, unsigned n, double p) :
		bookNo (s), units_sold (n), revenue (p * n) { }
	Sales_data (istream &is);

	std::string isbn () const { return this->bookNo; }
	Sales_data& combine (const Sales_data&);

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};



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

// 成员函数
Sales_data::Sales_data (istream &is)
{
	read (is, *this);
}

Sales_data& Sales_data::combine (const Sales_data & rhs)
{
	units_sold += rhs.units_sold;		// 把 rhs 的成员加到 this 对象的成员上
	revenue += rhs.revenue;
	return *this;					// 返回调用该函数的对象
}
#endif
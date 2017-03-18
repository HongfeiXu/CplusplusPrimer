/*
* 练习7.26：将 Sales_data::avg_price 定义成内联函数。
*/

#ifndef EX7_41_H
#define EX7_41_H

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;
using std::cout;
using std::endl;


class Sales_data {
	// 友元声明
	friend Sales_data add (const Sales_data &lhs, const Sales_data &rhs);	// 将这几个类 Sales_data的接口函数但不是成员函数声明为类的友元
	friend istream &read (istream &is, Sales_data &item);					// 从而这几个函数可以访问类的非公有成员
	friend ostream &print (ostream &os, const Sales_data &item);
public:
	// 非委托构造函数使用对应的实参初始化成员
	Sales_data (const string &s, unsigned n, double p) :
		bookNo (s), units_sold (n), revenue (p * n) 
	{
		cout << "非委托构造函数" << endl;
	}
	// 其余构造函数全部委托给另一个构造函数
	Sales_data () : Sales_data ("", 0, 0) { cout << "默认构造函数" << endl; }
	Sales_data (string s) : Sales_data (s, 0, 0) { cout << "string" << endl; }
	Sales_data (istream &is) : Sales_data ()
	{ 
		read (is, *this); 
		cout << "istream" << endl; 
	}
	std::string isbn () const { return this->bookNo; }
	Sales_data& combine (const Sales_data&);
private:
	double avg_price () const;
private:
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
Sales_data& Sales_data::combine (const Sales_data & rhs)
{
	units_sold += rhs.units_sold;		// 把 rhs 的成员加到 this 对象的成员上
	revenue += rhs.revenue;
	return *this;					// 返回调用该函数的对象
}

inline double Sales_data::avg_price () const		// 将此成员函数指定为 内联函数。
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
#endif
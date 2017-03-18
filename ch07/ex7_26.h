/*
* 练习7.26：将 Sales_data::avg_price 定义成内联函数。
*/

#ifndef EX7_26_H
#define EX7_26_H

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

class Sales_data {
	// 友元声明
	friend Sales_data add (const Sales_data &lhs, const Sales_data &rhs);		// 将这几个类 Sales_data的接口函数但不是成员函数声明为类的友元
	friend istream &read (istream &is, Sales_data &item);					// 从而这几个函数可以访问类的非公有成员
	friend ostream &print (ostream &os, const Sales_data &item);
public:
	Sales_data () = default;
	Sales_data (const string &s) : bookNo (s) { }
	Sales_data (const string &s, unsigned n, double p) :
		bookNo (s), units_sold (n), revenue (p * n) { }
	Sales_data (istream &is)
	{
		read (is, *this);
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


inline double Sales_data::avg_price () const		// 将此成员函数指定为 内联函数。
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
// // declarations for nonmember parts of the Sales_data interface.
Sales_data add (const Sales_data &lhs, const Sales_data &rhs);	
istream &read (istream &is, Sales_data &item);				
ostream &print (ostream &os, const Sales_data &item);
#endif
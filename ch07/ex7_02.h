/*
* 练习7.2：请向第67页练习中编写的类 Sales_data 中添加 combine 和 isbn 成员。
*/

#ifndef EX7_02_H
#define EX7_02_H

#include <string>

struct Sales_data {
	std::string isbn () const { return this->bookNo; }		
	Sales_data& combine (const Sales_data&);

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data& Sales_data::combine (const Sales_data & rhs)
{
	units_sold += rhs.units_sold;		// 把 rhs 的成员加到 this 对象的成员上
	revenue += rhs.revenue;
	return *this;					// 返回调用该函数的对象
}

#endif
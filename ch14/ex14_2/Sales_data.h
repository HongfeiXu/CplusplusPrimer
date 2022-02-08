#pragma once

#include <string>
#include <iostream>
#include <functional>

using std::istream;
using std::ostream;
using std::string;

class Sales_data;

namespace std {
	// 特例化hash类，以支持将Sales_data对象保存在无序容器中
	template<>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type;	// 默认情况下，此类型需要==
		size_t operator() (const Sales_data& s) const;
	};
} // namespace std


class Sales_data {
	// 友元声明
	friend ostream &operator<<(ostream &os, const Sales_data &item);
	friend istream &operator>>(istream &is, Sales_data &item);
	friend struct std::hash<Sales_data>;
public:
	Sales_data() = default;
	Sales_data(const string &s) : bookNo(s) { }
	Sales_data(const string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p * n)
	{
	}
	Sales_data(istream &is)
	{
		is >> *this;
	}
	std::string isbn() const { return this->bookNo; }
	Sales_data& operator+=(const Sales_data &rhs);
	bool operator==(const Sales_data& rhs) const;
private:
	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline double Sales_data::avg_price() const		// 将此成员函数指定为 内联函数。
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
// declarations for nonmember parts of the Sales_data interface.
ostream &operator<<(ostream &os, const Sales_data &item);
istream &operator >> (istream &is, Sales_data &item);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs);

void test_sales_data();

/*
* ��ϰ7.6�����ں��� add��read �� print���������Լ��İ汾��
*/

#ifndef EX7_11_H
#define EX7_11_H

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

struct Sales_data {
	// �����Ĺ��캯��
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



// �ǳ�Ա�����������ǽӿں���
istream &read (istream &is, Sales_data &item)		// IO �����ڲ��ܱ����������ͣ����ֻ�����������������ǡ�
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
	sum.combine (rhs);		// �� rhs �����ݳ�Ա�ӵ� sum ���С�
	return sum;
}

// ��Ա����
Sales_data::Sales_data (istream &is)
{
	read (is, *this);
}

Sales_data& Sales_data::combine (const Sales_data & rhs)
{
	units_sold += rhs.units_sold;		// �� rhs �ĳ�Ա�ӵ� this ����ĳ�Ա��
	revenue += rhs.revenue;
	return *this;					// ���ص��øú����Ķ���
}
#endif
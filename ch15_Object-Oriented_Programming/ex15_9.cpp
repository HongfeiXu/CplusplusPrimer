/*
练习 15.9：在什么情况下表达式的静态类型可能与动态类型不同？
请给出三个静态类型与动态类型不同的例子。
*/
#include <iostream>
#include <string>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) { }
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const
	{
		return n * price;
	}
	virtual ~Quote() = default;

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

class Bulk_quote final : public Quote  // Bulk_quote 继承自 Quote，并且限定 Bulk_quote 不能被其他类继承
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :  // 每个类控制它自己的成员初始化过程
		Quote(book, p), min_qty(qty), discount(disc) { }  // 先由 Quote 的构造函数初始化 Bulk_quote 的基类部分
	double net_price(std::size_t n) const override
	{
		if (n >= min_qty)
		{
			return n * (1 - discount) * price;  // 派生类 Bulk_quote 使用基类 Quote 成员 price
		}
		else
		{
			return n * price;
		}
	}

private:
	std::size_t min_qty = 0;  // 类内初始值
	double discount = 0;
};

double print_total(std::ostream &os, const Quote &item, size_t n);

int main()
{
	Bulk_quote bq1(std::string("Gone with the Wind"), 100.0, 20, 0.2);

	Quote *pq1 = &bq1;  // pq1: static type is Quote, dynamic type is Bulk_quote
	std::cout << pq1->net_price(20) << std::endl;
	Quote &rq1 = bq1;   // rq1: static type is Quote, dynamic type is Bulk_quote
	std::cout << rq1.net_price(20) << std::endl;
	
	Quote p1 = bq1;  // p1: static type is Quote, dynamic type is Quote
	std::cout << p1.net_price(20) << std::endl;

	return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

/*

1600
1600
2000
Press any key to continue . . .

*/
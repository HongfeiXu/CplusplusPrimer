/*
练习 15.3：定义你自己的 Quote 类和 print_total 函数。
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

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

int main()
{
	Quote q(std::string("Hello World!"), 100.0);

	print_total(std::cout, q, 10);

	return 0;
}

/*

ISBN: Hello World! # sold: 10 total due: 1000
Press any key to continue . . .

*/
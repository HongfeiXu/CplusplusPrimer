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
	Quote q(std::string("Gone with the Wind"), 100.0);
	print_total(std::cout, q, 20);

	Bulk_quote bq(std::string("Gone with the Wind"), 100, 20, 0.5);  // 购买量超过 20 时，超出的部分将以原价销售（打五折）
	print_total(std::cout, bq, 20);


	return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

/*

ISBN: Gone with the Wind # sold: 20 total due: 2000
ISBN: Gone with the Wind # sold: 20 total due: 1000
Press any key to continue . . .

*/
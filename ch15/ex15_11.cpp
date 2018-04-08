/*
练习 15.11：为你的 Quote 类添加一个名为 debug 的虚函数，令其分别显示每个类的数据成员。
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
	virtual void debug() const
	{
		std::cout << "data member of this class:\n";
		std::cout << "bookNo= " << bookNo << '\n';
		std::cout << "price= " << price << std::endl;;
	}

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
	void debug() const override final
	{
		Quote::debug();  // 调用基类中的虚函数
		std::cout << "min_qty: " << min_qty << '\n';
		std::cout << "discount: " << discount << std::endl;;
	}

private:
	std::size_t min_qty = 0;  // 类内初始值
	double discount = 0;
};

double print_total(std::ostream &os, const Quote &item, size_t n);

int main()
{
	Bulk_quote bq1(std::string("Gone with the Wind"), 100.0, 20, 0.2);
	bq1.debug();

	Quote q1(std::string("Gone with the Wind"), 100.0);
	q1.debug();

	return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

/*

data member of this class:
bookNo= Gone with the Wind
price= 100
min_qty: 20
discount: 0.2
data member of this class:
bookNo= Gone with the Wind
price= 100
Press any key to continue . . .


*/
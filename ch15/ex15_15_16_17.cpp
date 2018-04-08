/*
练习 15.15：定义你自己的 Disc_quote 和 Bulk_quote
练习 15.16：改写你在 15.2.2 节 练习中编写的数量受限的折扣策略，令其继承 Disc_quote
练习 15.17：尝试定义一个 Disc_quote 的对象，看看编译器给出的错误信息是什么。
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

// 用于保存折扣值和购买量的类，派生类使用这些数据可以实现不同的价格策略
class Disc_quote : public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc) { }
	double net_price(std::size_t) const = 0;  // 将 net_price 定义为纯虚函数，是的 Disc_quote 称为一个抽象基类，不能定义该类的对象。

protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

// 当同一书籍的销售量超过某个值时，启用折扣
// 折扣的值时一个小于 1 的正的小数值，以此来降低正常销售价格
class Bulk_quote final : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) :
		Disc_quote(book, price, qty, disc) { }
	double net_price(std::size_t n) const override final
	{
		if (n > quantity)
		{
			return n * (1 - discount) * price;
		}
		else
		{
			return n * price;
		}
	}
};

// 当购买书籍的数量不超过一个给定的限量时享受折扣，
// 如果购买量一旦超过了限量，则超出的部分将以原价销售。
class Limit_Quote final : public Disc_quote
{
public:
	Limit_Quote() = default;
	Limit_Quote(const std::string &book, double price, std::size_t qty, double disc) :
		Disc_quote(book, price, qty, disc) { }
	double net_price(std::size_t n) const override final
	{
		if (n <= quantity)
		{
			return n * (1 - discount) * price;
		}
		else
		{
			return quantity * (1 - discount) * price + (n - quantity) * price;
		}
	}
};

double print_total(std::ostream &os, const Quote &item, size_t n);

int main()
{
	// 策略1
	Bulk_quote bq(std::string("Gone with the Wind"), 100.0, 20, 0.2);
	print_total(std::cout, bq, 21);
	// 策略2
	Limit_Quote lq(std::string("The Song of Ice and Fire"), 100.0, 20, 0.2);
	print_total(std::cout, lq, 21);

	// error:
	// 'Disc_quote': cannot instantiate abstract class
	// due to following members:
	// 'double Disc_quote::net_price(std::size_t) const': is abstract

	// Disc_quote dq;


	return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

/*

ISBN: Gone with the Wind # sold: 21 total due: 1680
ISBN: The Song of Ice and Fire # sold: 21 total due: 1700
Press any key to continue . . .

*/
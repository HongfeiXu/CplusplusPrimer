/*
* 练习7.57：编写你自己的 Account 类。
*/

#include <string>

class Account {
public:
	void calculate () { amount += amount * interestRate; }
	static double rate () { return interestRate; }
	static void rate (double);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
	static constexpr int period = 30;		// period 是常量表达式
	double daily_tbl[period];
};

void Account::rate (double newRate)
{
	interestRate = newRate;
}

double Account::initRate ()
{
	return 0.3;
}

double Account::interestRate = initRate ();

constexpr int Account::period;	// 不带初始值的静态成员的定义，初始值在类内提供了。
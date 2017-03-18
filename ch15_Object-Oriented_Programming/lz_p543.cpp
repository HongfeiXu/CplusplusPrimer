/*
15.5 访问控制与继承 例子
*/

#include <iostream>

class Base
{
public:
	void pub_mem()
	{
		std::cout << "Hello, I am base!" << std::endl;
	}
protected:
	int prot_mem;
private:
	char priv_mem;
};

class Pub_Derv : public Base
{
	int f() { return prot_mem; }
	//char g() { return priv_mem; }
};

class Priv_Derv : private Base
{
	int f1() const { return prot_mem; }
};

class Prot_Derv : protected Base
{
	int f2() const { return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv
{
	// 正确： Base::prot_mem 在 Pub_Derv 中仍是 protected 的
	int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv
{
	// 错误： Base::prot_mem 在 Priv_Derv 中是 private 的
//	int use_base() { return prot_mem; }
};

struct Derived_from_Protect : public Prot_Derv
{
	int use_base() { return prot_mem; }
};

int main()
{
	Pub_Derv d1;  // 继承自 Base 的成员是 public 的
	Priv_Derv d2; // 继承自 Base 的成员是 private 的
	d1.pub_mem(); // 正确： pub_mem 在派生类中是 public 的
//	d2.pub_mem(); // 错误： pub_mem 在派生类中是 private 的

	Prot_Derv d3;
//	d3.pub_mem(); // 错误： pub_mem 在派生类中是 protected 的



	return 0;
}
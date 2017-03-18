/*
练习 15.18：
练习 15.19：假设 543 页和 544 页的每个类都有如下形式的成员函数：
void memfcn(Base &b) {b  =*this;}
对于每个类，分别判断上面的函数是否和发。
练习 15.20：编写代码检验你对前面两题的回答是否正确。

解答：判断派生类向基类转换的可访问性可以通过如下的方式来判断，
对于代码中的某个给定节点来说，如果基类的公有成员是可访问的，则派生类向积累的类型转换也是可访问的；反之则不行。
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
	void memfcn(Base &b) { b = *this; }
};

class Priv_Derv : private Base
{
	int f1() const { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

class Prot_Derv : protected Base
{
	int f2() const { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
	// 正确： Base::prot_mem 在 Pub_Derv 中仍是 protected 的
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv
{
	// 错误： Base::prot_mem 在 Priv_Derv 中是 private 的
	//	int use_base() { return prot_mem; }
	// 错误：此处基类的公有成员不可访问
//	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protect : public Prot_Derv
{
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

int main()
{
	// 正确
	Pub_Derv d1;
	Base *p = &d1;

	// 错误
	Priv_Derv d2;
//	p = &d2;

	// 错误
	Prot_Derv d3;
//	p = &d3;

	// 正确
	Derived_from_Public dd1;
	p = &dd1;

	// 错误
	Derived_from_Private dd2;
//	p = &dd2;

	// 错误
	Derived_from_Protect dd3;
//	p = &dd3;


	return 0;
}
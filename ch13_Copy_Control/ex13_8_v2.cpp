/*

练习 13.8：为 13.1.1 节（第443）页练习 13.5 中的 HasPtr 类编写赋值运算符。
类似拷贝构造函数，你的赋值运算符应该讲对象拷贝到 ps 指向的位置。
v2: use smart ptr

*/
#include <string>
#include <iostream>
#include <memory>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0)
	{
	}
	HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) { }
	HasPtr& operator=(const HasPtr&);  // 赋值运算符
	long count()
	{
		return ps.use_count();
	}
private:
	std::shared_ptr<std::string> ps;
	int i;
};

HasPtr& HasPtr::operator=(const HasPtr &orig)
{
	ps = std::make_shared<std::string>(*orig.ps);
	i = orig.i;
	return *this;
}

int main()
{
	HasPtr hp0(std::string("Hello"));
	std::cout << "hp0_before: " << hp0.count() << std::endl;
	HasPtr hp1 = hp0;
	std::cout << "hp0_after: " << hp0.count() << std::endl;
	std::cout << "hp1_after: " << hp1.count() << std::endl;

	return 0;
}

/*

hp0_before: 1
hp0_after: 1
hp1_after: 1
Press any key to continue . . .


测试结果表明，hp0和hp1中的指针各自维护一块内存，互不干扰。
*/
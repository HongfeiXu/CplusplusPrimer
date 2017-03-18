/*

练习 13.8：为 13.1.1 节（第443）页练习 13.5 中的 HasPtr 类编写赋值运算符。
类似拷贝构造函数，你的赋值运算符应该讲对象拷贝到 ps 指向的位置。

*/
#include <string>
#include <iostream>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : 
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) { }
	HasPtr& operator=(const HasPtr&);  // 赋值运算符
private:
	std::string *ps;
	int i;
};

// 这个赋值运算会有内存泄漏
//HasPtr& HasPtr::operator=(const HasPtr &orig)
//{
//	ps = new std::string(*orig.ps);
//	i = orig.i;
//	return *this;
//}

HasPtr& HasPtr::operator=(const HasPtr &orig)
{
	delete ps;
	ps = new std::string(*orig.ps);
	i = orig.i;
	std::cout << "hello" << std::endl;
	return *this;
}

int main()
{
	HasPtr hp0(std::string("Hello"));
	HasPtr hp1;
	hp1 = hp0;

	return 0;
}
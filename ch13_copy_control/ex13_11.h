/*

练习 13.11：为前面练习中的 HasPtr 类添加一个析构函数

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
	~HasPtr() { delete ps; }
private:
	std::string *ps;
	int i;
};


HasPtr& HasPtr::operator=(const HasPtr &orig)
{
	delete ps;
	ps = new std::string(*orig.ps);
	i = orig.i;
	std::cout << "hello" << std::endl;
	return *this;
}

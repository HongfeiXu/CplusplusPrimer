/*
* 练习7.9：对于7.1.2节练习7.5中的代码，添加读取和打印 Person 对象的操作。
*/
#ifndef EX7_9_H
#define EX7_9_H 

#include <string>
#include <iostream>

using std::istream;
using std::ostream;

struct Person {
	auto getName() const -> std::string const & { return name; }		// 常量成员函数
	auto getAddress () const -> std::string const & { return address; }

	std::string name;
	std::string address;
};

istream &read (istream &is, Person &p)
{
	is >> p.name >> p.address;
	return is;
}


ostream &print (ostream &os, const Person &p)
{
	os << p.getName() << " " << p.getAddress ();
	return os;
}

#endif
/*
* 练习7.22：修改你的 Person 类使其隐藏实现的细节。
*/
#ifndef EX7_22_H
#define EX7_22_H 

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

struct Person;
istream &read (istream &is, Person &p);

struct Person {
	friend istream &read (istream &is, Person &p);
	friend ostream &print (ostream &os, const Person &p);
public:
	Person () = default;
	Person(const string sname, const string saddr) : name(sname), address(saddr) { }
	Person (istream &is) { read (is, *this); }

	auto getName() const -> std::string const & { return name; }		// 常量成员函数
	auto getAddress () const -> std::string const & { return address; }
private:
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
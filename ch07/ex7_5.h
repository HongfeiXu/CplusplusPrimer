/*
* 练习7.5：在你的 Person 类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是 const 的呢？
* ？？？
*/
#ifndef EX7_5_H
#define EX7_5_H 

#include <string>

class Persion {
	auto getName() const -> std::string const & { return name; }		// 常量成员函数
	auto getAddress () const -> std::string const & { return address; }

	std::string name;
	std::string address;
};

#endif
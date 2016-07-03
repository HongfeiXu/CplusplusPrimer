// Book
#include <string>
#include <iostream>
using std::string;
using std::istream;

class Book {
public:
	// 非委托构造函数
	Book (unsigned isbn, string name, string author, string pudate) 
		: isbn_(isbn), name_(name), author_(author), pudate_(pudate) { }
	// 委托构造函数
	Book (): Book (0, "", "", "") { }

	Book (istream &in)
	{
		in >> isbn_ >> name_ >> author_ >> pudate_;
	}
private:
	unsigned isbn_;
	string name_;
	string author_;
	string pudate_;
};
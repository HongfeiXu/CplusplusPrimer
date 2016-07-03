// Book
#include <string>
#include <iostream>
using std::string;
using std::istream;

class Book {
public:
	Book () = default;	// 默认构造函数
	Book (unsigned isbn, string name, string author, string pudate) 
		: isbn_(isbn), name_(name), author_(author), pudate_(pudate) { }
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
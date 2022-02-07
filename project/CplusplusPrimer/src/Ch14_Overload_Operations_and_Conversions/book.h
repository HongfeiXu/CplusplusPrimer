#pragma once

// Book
#include <string>
#include <iostream>
using std::string;
using std::istream;

class Book {
	// 友元声明
	friend std::istream& operator>>(std::istream&, Book&);
	friend std::ostream& operator<<(std::ostream&, const Book&);
	friend bool operator==(const Book&, const Book&);
	friend bool operator!=(const Book&, const Book&);
	friend bool operator<(const Book&, const Book&);
	friend bool operator>(const Book&, const Book&);
	friend Book operator+(const Book&, const Book&);
public:
	Book() = default;	// 默认构造函数
	Book(unsigned isbn, string name, string author, string pudate)
		: isbn_(isbn), name_(name), author_(author), pudate_(pudate) { }
	Book(istream& in)
	{
		in >> *this;
	}
private:
	unsigned isbn_;
	string name_;
	string author_;
	string pudate_;
};

std::istream& operator>>(std::istream&, Book&);
std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
bool operator<(const Book&, const Book&);
bool operator>(const Book&, const Book&);

void test_book();

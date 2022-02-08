#include "book.h"

std::istream& operator>>(std::istream& in, Book& book)
{
	in >> book.isbn_ >> book.name_ >> book.author_ >> book.pudate_;
	if (!in)	// 输入失败，对象被赋予默认状态
		book = Book();
	return in;
}

std::ostream& operator<<(std::ostream& out, const Book& book)
{
	out << book.isbn_ << " " << book.name_ << " " << book.author_ << " " << book.pudate_;
	return out;
}

bool operator==(const Book& lhs, const Book& rhs)
{
	return lhs.isbn_ == rhs.isbn_;
}

bool operator!=(const Book& lhs, const Book& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Book& lhs, const Book& rhs)
{
	return lhs.isbn_ < rhs.isbn_;
}

bool operator>(const Book& lhs, const Book& rhs)
{
	return rhs < lhs;
}



void test_book()
{
	Book b1{ 12,"ha", "sda", "sdf" };
	Book b2{ 123,"ha", "sda", "sdf" };
	std::cout << b1 << std::endl;
	std::cout << (b1 == b2) << std::endl;
	Book b3;
	std::cin >> b3;
	std::cout << b3 << std::endl;
	std::cout << (b1 < b2) << std::endl;
}

/*

12 ha sda sdf
0

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 22964)已退出，代码为 0。
按任意键关闭此窗口. . .

*/


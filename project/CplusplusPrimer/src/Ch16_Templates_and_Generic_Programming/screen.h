#pragma once

#include <string>
#include <iostream>
using namespace std;


template<unsigned HEIGHT, unsigned WIDTH>
class Screen {
	friend ostream& operator<< (ostream& os, const Screen<HEIGHT, WIDTH>& c)
	{
		for (unsigned i = 0; i < c.height; ++i)
		{
			os << c.contents.substr(0, WIDTH) << endl;
		}
		return os;
	}

	friend istream& operator>> (istream& is, Screen<HEIGHT, WIDTH>& c)
	{
		char a;
		is >> a;
		string temp(HEIGHT * WIDTH, a);
		c.contents = temp;
		return is;
	}

public:
	typedef string::size_type pos;
	
	Screen() = default;
	Screen(char c) :contents(HEIGHT* WIDTH, c) { }
	char get() const
	{
		return contents[cursor];
	}
	Screen& move(pos r, pos c);

private:
	pos cursor{0};
	pos height{ HEIGHT };
	pos width{ WIDTH };
	string contents;
};

template<unsigned HEIGHT, unsigned WIDTH>
inline Screen<HEIGHT, WIDTH>& Screen<HEIGHT, WIDTH>::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

void test()
{
	Screen<5, 4> src('c');
	Screen<5, 4> src2;

	cout << src << endl;
	cin >> src2;
	cout << src2 << endl;
}

/*
cccc
cccc
cccc
cccc
cccc

b
bbbb
bbbb
bbbb
bbbb
bbbb


E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 33896)已退出，代码为 0。
按任意键关闭此窗口. . .
*/
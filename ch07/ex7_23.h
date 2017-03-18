/*
* 练习7.23：编写你自己的 Screen 类。
* 练习7.24：三个构造函数。
*/
#ifndef EX7_23_H
#define EX7_23_H

#include <string>
class Screen {
public:
	using pos = std::string::size_type;	// 定义一个类型成员

	Screen () = default;	// 默认构造函数
	Screen (pos w, pos h) : height(h), width(w), contents(h*w, ' ') { }
	Screen (pos w, pos h, char c): height(h), width(w), contents(h*w, c) { }

	char get () const
	{
		return contents[cursor];
	}
	char get (pos r, pos c) const;
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

inline char Screen::get (pos r, pos c) const	// 说明该函数为内联函数
{
	pos row = r * width;
	return contents[row + c];
}

#endif
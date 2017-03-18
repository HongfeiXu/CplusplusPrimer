/*
* 练习7.29：修改你的 Screen 类，令 move、set 和 display 函数返回 Screen 并检查程序的运行结果。
*/
#ifndef EX7_29_H
#define EX7_29_H

#include <string>
#include <iostream>

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
	Screen set (char);				// 设置光标所在位置的字符
	Screen set (pos, pos, char);	// 设置给定位置的字符
	Screen move (pos, pos);		// 移动光标
	Screen display (std::ostream &os)	// 打印 Screen 的内容
	{
		do_display (os);
		return *this;
	}
	const Screen display (std::ostream &os) const
	{
		do_display (os);
		return *this;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display (std::ostream &os) const { os << contents; }	// 对于公共代码使用私有功能函数
};

inline char Screen::get (pos r, pos c) const	// 说明该函数为内联函数
{
	pos row = r * width;
	return contents[row + c];
}

inline Screen Screen::set (char c)
{
	contents[cursor] = c;
	return *this;		// 将 this 对象作为左值返回
}

inline Screen Screen::set (pos row, pos col, char c)
{
	contents[row * width + col] = c;
	return *this;
}

inline Screen Screen::move (pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}

#endif
/*
* 练习7.32：定义你自己的 Screen 和 Window_mgr，其中 clear 是 Window_mgr 的成员，是 Screen 的友元。
*/
#ifndef EX7_32_H
#define EX7_32_H

#include <string>
#include <iostream>
#include <vector>

class Screen;

class Window_mgr {
public:
	// 窗口中每个屏幕的编号
	using ScreenIndex = std::vector<Screen>::size_type;
	// 按照编号将指定的 Screen 重置为空白
	void clear (ScreenIndex);
private:
	std::vector<Screen> screens;
};

class Screen {
	//	friend class Window_mgr;		// 把 Window_mgr 指定为 Screen 的友元，使得 Window_mgr 的成员可以访问 Screen 类的私有成员
	friend void Window_mgr::clear (ScreenIndex);		// 令 Window_mgr 的成员函数 clear 作为友元，只为 clear 提供访问权限
public:
	using pos = std::string::size_type;	// 定义一个类型成员

	Screen () = default;	// 默认构造函数
	Screen (pos w, pos h) : height (h), width (w), contents (h*w, ' ') { }
	Screen (pos w, pos h, char c) : height (h), width (w), contents (h*w, c) { }
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

void Window_mgr::clear (ScreenIndex i)
{
	if (i >= screens.size ()) return;		//  // judge for out_of_range.
	// s 是一个 Screen 的引用，指向我们想清空的那个屏幕
	Screen &s = screens[i];
	// 将那个选定的 Screen 重置为空白
	s.contents = std::string (s.height * s.width, ' ');
}

#endif
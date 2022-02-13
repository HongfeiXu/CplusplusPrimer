/*

练习14.44
编写一个简单的桌面计算器使其能处理二元运算。

*/
#include <functional>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int add(int i, int j) { return i + j; }
auto mod = [](int i, int j) {return  i % j; };
struct divide {
	int operator()(int denominator, int divisor)
	{
		return denominator / divisor;
	}
};

int main()
{
	//map<string, int(*)(int, int)> binops; // binops.insert({ "/", divide() }); 出错
	map<string, function<int(int, int)>> binops{
		{ "+", add }, // 函数指针
		{ "-", minus<int>() }, // 标准库函数对象
		{ "*", [](int i, int j) {return i * j; } }, // 未命名的lambda
		{ "/", divide() }, // 用户定义的函数对象
		{ "%", mod }, // 命名了的lambda对象
	};

	cout << binops["%"](10, 3) << endl;
	cout << binops["+"](1, 2) << endl;
	cout << binops["*"](2, 3) << endl;

	return 0;
}

/*
1
3
6

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 33908)已退出，代码为 0。
按任意键关闭此窗口. . .
*/

/*

练习14.34
定义一个函数对象类，令其执行if-then-else 的操作：该类的调用运算符接受三个形参，它首先检查第一个形参，如果成功返回第二个形参值；如果不成功返回第三个形参的值。

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class IfThenElse {
public:
	int operator()(bool b, int iA, int iB)
	{
		return b ? iA : iB;
	}
};

int main()
{
	IfThenElse ifThenElse;
	std::cout << ifThenElse(false, 1, 2) << std::endl;

	return 0;
}

/*
2

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 67428)已退出，代码为 0。
按任意键关闭此窗口. . .
*/

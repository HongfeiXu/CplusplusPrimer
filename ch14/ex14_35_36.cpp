/*

练习14.35
编写一个类似于 PrintString 的类，令其从 istream 中读取一行输入，然后返回一个表示我们所读内容的string。如果读取失败，返回空string。

练习14.36
使用前一个练习定义的类读取标准输入，将每一行保存为 vector 的一个元素。

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class PrintString {
public:
	PrintString(std::ostream& o, char c)
		: os(o), sep(c) { }

	void operator()(const std::string& s) const
	{
		os << s << sep;
	}
private:
	std::ostream& os{ std::cout };
	char sep{ ' ' };
};

class GetInput {
public:
	GetInput(std::istream& i = std::cin) : is(i) {}

	std::string operator()() const
	{
		std::string str;
		std::getline(is, str);
		return str;
	}

private:
	std::istream& is;
};

int main()
{
	GetInput getInput(std::cin);
	std::string a = getInput();
	std::cout << "a = " << a << std::endl;

	std::vector<std::string> vs;
	for (std::string tmp; !(tmp = getInput()).empty(); vs.push_back(tmp));
	for_each(vs.cbegin(), vs.cend(), PrintString(std::cout, '-'));
	return 0;
}

/*
a
a = a
hello
world
fuck
you
^Z
hello-world-fuck-you-
E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 65988)已退出，代码为 0。
按任意键关闭此窗口. . .
*/

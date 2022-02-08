#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class SizeComp {
public:
	SizeComp(size_t n) : sz(n) { }
	bool operator()(const std::string& s) const
	{
		return s.size() >= sz;
	}
private:
	std::size_t sz;
};

int main()
{
	std::size_t sz = 3;
	std::vector<std::string> words{ "ap", "pen", "pc", "philips" };
	auto wc = std::find_if(words.begin(), words.end(),
		[sz](const std::string& a)
		{ return a.size() >= sz; });
	if (wc != words.end())
		std::cout << *wc << std::endl;

	auto wc2 = std::find_if(words.begin(), words.end(), SizeComp(5));
	if (wc2 != words.end())
		std::cout << *wc2 << std::endl;
}

/*
pen
philips

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 80176)已退出，代码为 0。
按任意键关闭此窗口. . .
*/

/*

练习16.63
定义一个函数模版，统计一个给定值在一个vecor中出现的次数。测试你的函数，分别传递给它一个double的vector，一个int的vector以及一个string的vector。

练习16.64
为上一题的模版编写特例化版本来处理vector<const char*>。编写程序使用这个特例化版本。

*/

#include <vector>
#include <string>
#include <cstddef>
#include <iostream>

using namespace std;

template<typename T>
std::size_t getCnt(const std::vector<T>& vec, T val)
{
	std::size_t cnt = 0;
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
	{
		if (*it == val)
		{
			++cnt;
		}
	}
	return cnt;
}

// 用来支持 getCnt(vec_str, "hello")
std::size_t getCnt(const std::vector<std::string>& vec, const char* p)
{
	return getCnt(vec, std::string(p));
}

// 模板特例化，用来支持 getCnt(vec_cstr, "a")
template<>
std::size_t getCnt(const std::vector<const char*> const& vec, const char* p)
{
	std::size_t cnt = 0;
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
	{
		if (*it == p)
		{
			++cnt;
		}
	}
	return cnt;
}


int main()
{
	auto veci = std::vector<int>{ 1,2,3,4,5,1,2,3 };
	std::cout << getCnt(veci, 2) << std::endl;

	auto vecd = std::vector<double>{ 1.2,2.3,3.4,1.2 };
	std::cout << getCnt(vecd, 1.2) << std::endl;

	auto vecstr = std::vector<std::string>{ "hello", "world", "hello" };
	std::cout << getCnt(vecstr, "hello") << std::endl;

	auto vec_cstr = std::vector<const char*>{ "a", "b", "a" };
	std::cout << getCnt(vec_cstr, "a") << std::endl;

	return 0;
}

/*

2
2
2
2

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 49544)已退出，代码为 0。
按任意键关闭此窗口. . .

*/

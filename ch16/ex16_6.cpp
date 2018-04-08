/*
*
*  练习 16.6：你认为接受一个数组实参的标准函数库 begin 和 end 是如何工作的？
*  定义你自己版本的 begin 和 end。
*
*/

#include <vector>
#include <list>
#include <string>
#include <iostream>

namespace ch16
{
	template <typename T, unsigned N>
	void print(const T(&arr)[N])
	{
		for (auto elem : arr)
			std::cout << elem << std::endl;
	}

	template <typename T, unsigned N>
	T* begin(T(&arr)[N])
	{
		return arr;
	}

	template <typename T, unsigned N>
	T* end(T(&arr)[N])
	{
		return arr + N;
	}
}

int main()
{
	std::string arr[3] = { std::string("Hello"), std::string("World"), std::string("WOW") };

	auto beg = ch16::begin(arr);
	auto end = ch16::end(arr);

	while (beg != end)
	{
		std::cout << *beg << std::endl;
		++beg;
	}

	return 0;
}

/*

Hello
World
WOW
Press any key to continue . . .

*/
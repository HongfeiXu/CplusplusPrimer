/*
*
*  练习 16.7：编写一个 constexpr 模板，返回给定数组的大小。
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

	template <typename T, unsigned N>
	constexpr unsigned getSize(const T(&arr)[N])
	{
		return N;
	}
}

int main()
{
	std::string arr[] = { std::string("Hello"), std::string("World"), std::string("WOW") };
	std::cout << ch16::getSize(arr) << std::endl;

	char c[] = "s";
	std::cout << ch16::getSize(c) << std::endl;
	// the output is 2, as '\0' is added at the end of the array

	return 0;
}

/*

3
2
Press any key to continue . . .

*/
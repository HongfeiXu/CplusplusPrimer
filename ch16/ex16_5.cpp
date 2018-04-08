/*
*
*  练习16.5：为 6.2.4 节（第 195 页）中的 print 函数编写模板版本，
*  它接受一个数组的引用，能处理任意大小、任意元素类型的数组。
*
*/

#include <vector>
#include <list>
#include <string>
#include <iostream>

namespace ch16
{
	template <typename T, unsigned N>
	void print(const T (&arr)[N])
	{
		for (auto elem : arr)
			std::cout << elem << std::endl;
	}
}

int main()
{
	std::string arr[3] = { std::string("Hello"), std::string("World"), std::string("WOW") };
	ch16::print(arr);

	int arr_1[4] = { 1,0,2,4 };
	ch16::print(arr_1);

	return 0;
}

/*

Find 1024 in the vec
Find Wow in the lst
Press any key to continue . . .

*/
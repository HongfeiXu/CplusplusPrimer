/*
*
*  练习16.4：编写行为类似标准库 find 算法的模板。函数需要两个模板类型参数，一个表示函数的迭代器参数，另一个表示值的类型。
*  使用你的函数在一个 vector<int> 和一个 list<string> 中查找给定值。
*  阅读 cppreference 中的 find 代码
*
*/

#include <vector>
#include <list>
#include <string>
#include <iostream>

namespace ch16
{
	template <typename InputIt, typename T>
	InputIt find(InputIt first, InputIt last, const T &value)
	{
		for (; first != last; first++)
		{
			if (*first == value)
			{
				return first;
			}
		}
		return last;
	}
}

int main()
{
	std::vector<int> vec{ 1,2,1024, 4 };
	std::list<std::string> lst{ "Hello", "World", "Wow" };

	auto temp_iter = ch16::find(vec.begin(), vec.end(), 1024);
	if (temp_iter != vec.end())
	{
		std::cout << "Find " << *temp_iter << " in the vec" << std::endl;
	}

	auto temp_iter_1 = ch16::find(lst.begin(), lst.end(), std::string("Wow"));
	if (temp_iter_1 != lst.end())
	{
		std::cout << "Find " << *temp_iter_1 << " in the lst" << std::endl;
	}

	return 0;
}

/*

Find 1024 in the vec
Find Wow in the lst
Press any key to continue . . .

*/
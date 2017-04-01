/*
*
*  ��ϰ16.4����д��Ϊ���Ʊ�׼�� find �㷨��ģ�塣������Ҫ����ģ�����Ͳ�����һ����ʾ�����ĵ�������������һ����ʾֵ�����͡�
*  ʹ����ĺ�����һ�� vector<int> ��һ�� list<string> �в��Ҹ���ֵ��
*  �Ķ� cppreference �е� find ����
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
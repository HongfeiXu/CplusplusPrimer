/*
*
*  ��ϰ16.5��Ϊ 6.2.4 �ڣ��� 195 ҳ���е� print ������дģ��汾��
*  ������һ����������ã��ܴ��������С������Ԫ�����͵����顣
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
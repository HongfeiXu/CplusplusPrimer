/*
* ��ϰ3.35 ��дһ�γ�������ָ�뽫�����е�Ԫ����Ϊ0��
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main ()
{
	constexpr size_t sz = 5;
	int arr[sz] = { 1, 2, 3, 4, 5 };
	int *beg = arr;
	int *end = arr + sz;
	while (beg != end)
	{
		*beg = 0;
		++beg;
	}
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
		
	return 0;
}

/*

0 0 0 0 0
�밴���������. . .

*/
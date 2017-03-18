/*
* ��ϰ4.21����дһ�γ���ʹ�������������vector<int>���ҵ���ЩԪ�ص�ֵ��������Ȼ����Щ����ֵ������
*/

#include <iostream>
#include <cstring>
#include <vector>

using std::vector;
using std::cout; 
using std::endl;


int main ()
{
	vector<int> vi{ 1, 2, 3, 4, 5, 6 };
	for (auto item : vi)
	{
		cout << item << " ";
	}
	cout << endl;

	for (auto &item : vi)
	{
		item % 2 == 0 ? item : item *= 2;
	}

	for (auto item : vi)
	{
		cout << item << " ";
	}
	cout << endl;

	return 0;
}

/*

1 2 3 4 5 6
2 2 6 4 10 6
�밴���������. . .

*/
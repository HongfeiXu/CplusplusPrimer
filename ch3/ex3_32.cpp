/*
* ��ϰ3.32����дһ�γ��򣬶���һ������10��int�����飬��ÿ��Ԫ�ص�ֵ�������±�ֵ��
* �����������鿽��������һ�����顣
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main ()
{
	int array[10];
	for (size_t i = 0; i < 10; i++)
		array[i] = i;
	cout << "array:" << endl;
	for (size_t i = 0; i < 10; i++)
		cout << array[i] << " ";
	cout << endl;

	int array_2[10];
	for (size_t i = 0; i < 10; i++)
		array_2[i] = array[i];
	cout << "array_2:" << endl;
	for (size_t i = 0; i < 10; i++)
		cout << array_2[i] << " ";
	cout << endl;
		
	return 0;
}

/*

array:
0 1 2 3 4 5 6 7 8 9
array_2:
0 1 2 3 4 5 6 7 8 9
�밴���������. . .

*/
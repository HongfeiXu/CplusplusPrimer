/*
* ��ϰ3.31����дһ�γ��򣬶���һ������10��int�����飬��ÿ��Ԫ�ص�ֵ�������±�ֵ��
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
	for (size_t i = 0; i < 10; i++)
		cout << array[i] << " ";
	cout << endl;
		
	return 0;
}

/*

0 1 2 3 4 5 6 7 8 9
�밴���������. . .

*/
/*
* ��ϰ6.22����дһ�����������佻������intָ�롣
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swapIntPointer (int *&a, int *&b)		// a �� int *���ͱ���������
{
	int *temp;
	temp = a;
	a = b;
	b = temp;
}

int main ()
{
	int a = 3, b = 4;
	int *pa = &a, *pb = &b;
	cout << *pa << " " << *pb << endl;
	swapIntPointer (pa, pb);
	cout << *pa << " " << *pb << endl;

	return 0;
}


/*

3 4
4 3
�밴���������. . .

*/
/*
* ��ϰ6.12���޸���ϰ6.10�ĳ���ʹ�����ö���ָ�뽻������������ֵ��
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap (int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main ()
{
	int a = 3, b = 4;
	cout << a << " " << b << endl;
	swap (a, b);
	cout << a << " " << b << endl;
	  
	return 0;
}
 

/*

3 4
4 3
�밴���������. . .

*/
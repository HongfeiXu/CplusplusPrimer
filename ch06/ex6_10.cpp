/*
* ��ϰ6.10����дһ��������ʹ��ָ���βν�������������ֵ���ڴ����е��øú��������ת����Ľ�����Դ���֤��������ȷ�ԡ�
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main ()
{
	int a = 3, b = 2;
	cout << a << " " << b << endl;
	swap (&a, &b);
	cout << a << " " << b << endl;

	return 0;
}
 

/*

3 2
2 3
�밴���������. . .

*/
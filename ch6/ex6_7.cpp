/*
* ��ϰ6.7 �� ��дһ��������������һ�α�����ʱ����0���Ժ�ÿ�α����÷���ֵ��1.
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

size_t count_calls ()
{
	static size_t ctr = 0;
	return ctr++;
}

int main ()
{
	for (size_t i = 0; i != 10; i++)
		cout << count_calls () << endl;

	return 0;
}

/*

0
1
2
3
4
5
6
7
8
9
�밴���������. . .

*/
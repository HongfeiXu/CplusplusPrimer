/*
* ��ϰ3.1��ʹ��ǡ����using��������1.4.1�ں�2.6.2�ڵ���ϰ��
* ��ϰ1.10����д������ʾ�û�����������������ӡ��������������ָ����Χ�ڵ�����������
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main ()
{
	int a, b;
	cin >> a >> b;
	if (a <= b)
	{
		for (int i = a; i <= b; i++)
		{
			cout << i << endl;
		}
	}
	else
	{
		for (int i = b; i <= a; i++)
		{
			cout << i << endl;
		}
	}

	return 0;
}

/*

19 2
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
�밴���������. . .

*/
/*
* ��ϰ6.21����дһ�������������������������һ����int���͵�������һ����intָ�롣�����Ƚ�int��ֵ��ָ����ָ��ֵ�����ؽϴ���Ǹ���
* �ú�����ָ�������Ӧ����ʲô��
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int getBigger (int a, const int *b)
{
	if (a >= *b)
		return a;
	else
		return *b;
}

int main ()
{
	int a = 0, b = 0;
	while (cin >> a >> b)
		cout << "The bigger one is " << getBigger (a, &b) << endl;


	return 0;
}


/*

3 4
The bigger one is 4
10 9
The bigger one is 10
^Z
�밴���������. . .

*/
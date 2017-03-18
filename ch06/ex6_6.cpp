/*
* ��ϰ6.6��˵���βΡ��ֲ������Լ��ֲ���̬���������𡣱�дһ��������ͬʱ�õ���������ʽ��
* ����printStars������� numOfStars����� numOfStars ���Ǻţ���ʹ�þ�̬�ֲ����� ctr ͳ���Լ��ǵڼ��������
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printStars (unsigned numOfStars)
{
	static size_t ctr = 0;
	cout << "Line " << ++ctr << ": ";
	for (unsigned i = 0; i != numOfStars; ++i)
	{
		cout << "*";
	}
	cout << endl;
}

int main ()
{
	printStars (3);
	printStars (10);
	printStars (5);

	return 0;
}

/*

Line 1: ***
Line 2: **********
Line 3: *****
�밴���������. . .

*/
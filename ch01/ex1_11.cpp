/*
* ��ϰ1.11����д������ʾ�û�����������������ӡ��������������ָ���ķ�Χ�ڵ�����������
*/

#include <iostream>

int main ()
{
	int a, b;
	std::cout << "Enter 2 numbers" << std::endl;
	std::cin >> a >> b;
	if (a <= b)
		while (a <= b)
		{
			std::cout << a << " ";
			++a;
		}
	else
		while (b <= a)
		{
			std::cout << b << " ";
			++b;
		}
	std::cout << std::endl;

	return 0;
}

/*

Enter 2 numbers
10 0
0 1 2 3 4 5 6 7 8 9 10
�밴���������. . .

*/

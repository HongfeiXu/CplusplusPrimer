/*
* ��ϰ1.10����д����ʹ�õݼ��������ѭ���а��ݼ�˳���ӡ��10��0֮���������
*/

#include <iostream>
int main ()
{
	int val = 10;
	while (val >= 0)
	{
		std::cout << val << " ";
		--val;
	}
	std::cout << std::endl;

	return 0;
}

/*

10 9 8 7 6 5 4 3 2 1 0
�밴���������. . .

*/
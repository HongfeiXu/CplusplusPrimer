/*
* ��ϰ1.9����д����ʹ��whileѭ����50��100��������ӡ�
*/
#include <iostream>
int main ()
{
	int sum = 0, val = 50;
	while (val <= 100)
	{
		sum += val;
		++val;
	}
	std::cout << "Sum of 50 to 100 inclusive is "
		<< sum << std::endl;

	return 0;
}

/*

Sum of 50 to 100 inclusive is 3825
�밴���������. . .

*/
/*
* ��ϰ1.16����д���򣬴�cin��ȡһ�����������͡�
* ע����Windowsϵͳ�У������ļ��������ķ�������CTRL+Z����UNIXϵͳ�У�CTRL+D��
*/

#include <iostream>
int main ()
{
	int sum = 0, value = 0;
	while (std::cin >> value)
		sum += value;
	std::cout << "Sum is " << sum << std::endl;

	return 0;
}

/*

19 8 -5 200 ^Z
Sum is 222
�밴���������. . .

*/
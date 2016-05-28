/*
* 练习1.11：编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。
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
请按任意键继续. . .

*/

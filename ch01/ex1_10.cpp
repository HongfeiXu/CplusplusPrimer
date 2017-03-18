/*
* 练习1.10：编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。
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
请按任意键继续. . .

*/
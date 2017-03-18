/*
* 使用for循环重做1.4.1节中的所有练习。
*/
#include <iostream>
int main ()
{	
	int sum = 0, val = 0;
	for (val = 50; val <= 100; val++)
		sum += val;
	std::cout << "Sum of 50 to 100 inlusive is "
		<< sum << std::endl;
	
	for (val = 10; val >= 0; val--)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	int a = 0, b = 0;
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

Sum of 50 to 100 inlusive is 3825
10 9 8 7 6 5 4 3 2 1 0
Enter 2 numbers
10 42
10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42
请按任意键继续. . .

*/

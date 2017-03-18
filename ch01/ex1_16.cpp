/*
* 练习1.16：编写程序，从cin读取一组数，输出其和。
* 注：在Windows系统中，输入文件结束符的方法是敲CTRL+Z。在UNIX系统中，CTRL+D。
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
请按任意键继续. . .

*/
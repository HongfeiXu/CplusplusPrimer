/*
* 练习6.4：编写一个用户交互函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact (int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}

int askuser ()
{
	int val;
	cout << "Please enter a number: ";
	cin >> val;
	return val;
}

int main ()
{
	int val = askuser ();
	cout << fact (val) << endl;

	return 0;
}

/*

Please enter a number: 5
120
请按任意键继续. . .

*/
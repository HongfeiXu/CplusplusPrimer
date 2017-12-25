/*
* 练习5.25：编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。
* 使用try语句块去补货异常。catch子句应该为用户输出一条提示信息，询问其是否输出新数并重新执行try语句块的内容。
*/
#include <iostream>
#include <stdexcept>

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;

int main ()
{
	int a, b;
	while (cin >> a >> b)
	{
		try 
		{
			if (b == 0)		// 如果除数为0，抛出异常
				throw runtime_error ("除数不能为0！");
			cout << a << " / " << b << " = " << a / b << endl;
		}
		catch (runtime_error err)	// 处理异常
		{
			cout << err.what()	// 输出异常信息
				<< "\nTry again? Enter y or n" << endl;		// 询问是否继续
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;		// 跳出while循环
		}
	}

	return 0;
}

/*

12 3
12 / 3 = 4
12 0
除数不能为0！
Try again? Enter y or n
y
9 19
9 / 19 = 0
1 0
除数不能为0！
Try again? Enter y or n
n
请按任意键继续. . .

*/
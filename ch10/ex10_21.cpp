/*
*	练习 10.21：编写一个lambda，捕获一个局部 int 变量，并递减变量值，直至它变为0.
*	一旦变量变为0，再调用 lamdba 应该不再递减变量。
*	lamdba 应该返回一个 bool 值，指出捕获的变量是否为 0.
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
	int var = 10;

	auto f = [&var]() -> bool
	{
		if(var > 0)
			return --var ? false : true;
		else
			return true;
	};

	while(!f())
		cout << var << " ";
	cout << var << endl;

	return 0;
}

/*

9 8 7 6 5 4 3 2 1 0
请按任意键继续. . .

*/
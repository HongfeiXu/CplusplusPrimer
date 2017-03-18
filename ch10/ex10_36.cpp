/*
练习 10.36：使用 find 在一个 int 的 list 中查找最后一个值为 0 的元素。
*/

#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	list<int> lstInt { 0, 1, 2, 3, 4, 0, 6, 7, 8, 9 };

	auto lastZero = find(lstInt.crbegin(), lstInt.crend(), 0);
	if(lastZero == lstInt.crend())
	{
		cout << "The value 0 is not present!" << endl;
	}
	else
	{
		cout << *lastZero << endl;
		cout << "The distance between the last 0 and crbegin:\n";
		cout << distance(lstInt.crbegin(), lastZero) << endl;
	}

	return 0;
}

/*

0
The distance between the last 0 and crbegin:
4
请按任意键继续. . .

*/
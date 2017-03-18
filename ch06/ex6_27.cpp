/*
* 练习6.27：编写一个函数，它的参数是 initializer_list<int> 类型的对象，函数的功能是计算列表中所有元素的和。
*/

#include <iostream>
#include <initializer_list>

using std::initializer_list;
using std::cout;
using std::cin;
using std::endl;

int sum (initializer_list<int> intList)
{
	int ret = 0;
	for (auto item : intList)
		ret += item;
	return ret;
}

int main ()
{
	cout << sum ({ 1, 2, 3, 4, 5 }) << endl;
	cout << sum ({ 6, 7, 8, 9, 10 }) << endl;
	return 0;
}


/*

15
40
请按任意键继续. . .

*/
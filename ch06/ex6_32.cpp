/*
* 练习6.32：下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。
*
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int &get (int *array, int index) { return array[index]; };		// 返回引用的函数

int main ()
{
	int ia[10];
	for (int i = 0; i != 10; ++i)
	{
		get (ia, i) = i;
	}
	for (auto i : ia)
		cout << i << " ";
	cout << endl;
	return 0;
}

/*

0 1 2 3 4 5 6 7 8 9
请按任意键继续. . .

*/
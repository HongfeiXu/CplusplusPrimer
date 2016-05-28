/*
* 练习3.23：编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变为原来的两倍。
* 输出所有vector对象的内容，检查程序是否正确。
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back (i);
	// 输出original v
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	for (auto &i : v)	// 对v中的每个元素
		i = 2 * i;
	// 输处new v
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	
	return 0;
}

/*

0 1 2 3 4 5 6 7 8 9
0 2 4 6 8 10 12 14 16 18
请按任意键继续. . .

*/
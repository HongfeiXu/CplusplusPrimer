/*
* 练习3.24：使用迭代器重做练习3.20。
* 读入一组整数，并把他们存入一个vector对象，将每对相邻整数的和输出出来。
* 改写你的程序，这次要求先输出第1个和最后1个元素的和，接着输出第2个和倒数第2个元素的和，以此类推。
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
	for (int item; cin >> item; v.push_back (item));
	for (auto beg = v.cbegin (); beg != v.cend () - 1; ++beg)		// beg一直到vector的倒数第2个元素
		cout << *beg + *(beg + 1) << " ";		// 将当前元素与相邻的元素相加
	cout << endl;
	auto mid = v.cbegin () + (v.cend () - v.cbegin ()) / 2;
	for (auto beg = v.cbegin (); beg < mid; ++beg)		// 先输出第1个和最后1个元素的和，接着输出第2个和倒数第2个元素的和
	{
		cout << *beg + *(v.cend () - 1 - (beg - v.cbegin ())) << " ";
	}
	if (v.size () % 2 != 0)
		cout << *mid;
	if (!v.empty ())
		cout << endl;

	return 0;
}

/*

1 2 3 4 5^Z
3 5 7 9
6 6 3
请按任意键继续. . .

1 2 3 4 5 6 7 8
^Z
3 5 7 9 11 13 15
9 9 9 9
请按任意键继续. . .

*/
/*
* 练习3.25：3.3.3节（第93页）划分分数段的程序是使用下标运算符实现的，
* 请利用迭代器改写该程序并实现完全相同的功能。
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	vector<unsigned> scores (11, 0);
	for (unsigned grade; cin >> grade; )
	{
		if (grade <= 100)
			++(*(scores.begin () + grade / 10));
	}
	// 输出
	for (auto item : scores)
		cout << item << " ";
	cout << endl;
	return 0;
}

/*

42 65 95 100 39 67 95 76 88 76 83 92 76 93
^Z
0 0 0 1 1 0 2 3 2 4 1
请按任意键继续. . .

*/
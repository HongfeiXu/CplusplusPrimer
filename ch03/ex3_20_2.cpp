/*
* 练习3.20_2：读入一组整数，并把他们存入一个vector对象，将每对相邻整数的和输出出来。
* 改写你的程序，这次要求先输出第1个和最后1个元素的和，接着输出第2个和倒数第2个元素的和，以此类推。
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	vector<int> v;
	int temp;
	while (cin >> temp)
		v.push_back (temp);
	auto size = v.size ();
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	for (vector<int>::size_type i = 0; i < size / 2; i++)
	{
		cout << v[i] + v[size - i - 1] << " ";
	}
	if (size % 2 != 0)		// 奇数个元素时，最后输出中间元素的值。
	{
		cout << v[size  / 2];
	}
	cout << endl;


	return 0;
}

/*

1 2 3 4 5^Z
1 2 3 4 5
6 6 3
请按任意键继续. . .

1 2 3 4 5 6^Z
1 2 3 4 5 6
7 7 7
请按任意键继续. . .

*/
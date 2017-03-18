/*
* 练习3.20：读入一组整数，并把他们存入一个vector对象，将每对相邻整数的和输出出来。
* 
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
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	for (vector<int>::size_type i = 0; i < v.size() - 1; i++)
	{
		cout << v[i] + v[i + 1] << " ";
	}
	cout << endl;


	return 0;
}

/*

1 2 3 4 5 6
^Z
1 2 3 4 5 6
3 5 7 9 11
请按任意键继续. . .

*/
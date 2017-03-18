/*
*	练习 10.1：编写程序，读取 int 序列存入 vector 中，打印有多少个元素的值等于给定值。
*/

#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vi;
	int target = 23;
	int temp;

	while(cin >> temp)
	{
		vi.push_back(temp);
	}

	auto number = count(vi.begin(), vi.end(), target);

	cout << "There are " << number << " '23'.\n";

	return 0;
}

/*

23 10 29 23 100 -20
^Z
There are 2 '23'.
请按任意键继续. . .

*/
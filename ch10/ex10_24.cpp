/*
*	练习 10.24：给定一个 string，使用 bind 和 check_size 在一个 int 的 vector 中查找
*	第一个大于 string 长度的值。
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

bool check_size(const string &s, string::size_type sz)
{
	return s.size() <= sz;
}

int main()
{
	string s = "Hello";
	vector<int> vi { 1, 2, 3, 4, 6, 99, 12 };

	auto result = find_if(vi.begin(), vi.end(), bind(check_size, s, placeholders::_1));
	cout << *result << endl;

	return 0;
}

/*

6
请按任意键继续. . .

*/
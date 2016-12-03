/*
*	练习 10.27：使用 unique_copy 将一个 vector 中不连续重复的元素拷贝到一个初始为空的 list 中
*	延伸，去除字符串中多余的空格字符 "The      string    with many       spaces!"
*/

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vi { 1, 1, 3, 3, 5, 5, 7, 7, 9 };
	list<int> li;

	cout << "before: ";
	for_each(vi.cbegin(), vi.cend(), [](const int &i){cout << i << " "; });
	cout << endl;

	unique_copy(vi.cbegin(), vi.cend(), back_inserter(li));
	cout << "after: ";
	for_each(li.cbegin(), li.cend(), [](const int &i){cout << i << " "; });
	cout << endl;

	string s1("The      string    with many       spaces!");
	cout << "before: " << s1 << '\n';

	string s2;
	unique_copy(s1.cbegin(), s1.cend(), back_inserter(s2), [](char c1, char c2) {return c1 == ' ' && c2 == ' '; });
	cout << "after:	" << s2 << endl;
	
	return 0;
}

/*

1 3 5 7 9
请按任意键继续. . .

*/
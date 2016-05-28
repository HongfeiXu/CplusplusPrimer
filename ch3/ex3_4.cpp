/*
* 练习3.3：编写一段程序读入两个字符串，比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。
* 改写上述程序，比较输入的两个字符串是否登场，如果不等长，输出长度较大的那个字符串。
*/

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;


int main ()
{
	string s1, s2;
	cin >> s1 >> s2;
	// 比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。
	if (s1 == s2)
		cout << s1 << "==" << s2 << endl;
	else if (s1 < s2)
		cout << s2 << endl;
	else
		cout << s1 << endl;
	// 比较输入的两个字符串是否登场，如果不等长，输出长度较大的那个字符串。
	if (s1.size () == s2.size ())
		cout << s1 << " 's size equals to " << s2 << endl;
	else if (s1.size () < s2.size ())
		cout << s2 << endl;
	else
		cout << s1 << endl;

	return 0;
}

/*

hello world
world
hello 's size equals to world
请按任意键继续. . .

*/
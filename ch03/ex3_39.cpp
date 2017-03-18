/*
* 练习3.39：编写一段程序，比较两个string对象。再编写一段程序，比较两个C风格字符串的内容。
*/

#include <iostream>
#include <string>
#include <cstring>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	// 比较两个string对象
	string s1("Hello");
	string s2("Halo");

	if (s1 < s2)
		cout << s1 << " < " << s2 << endl;
	else if (s1 == s2)
		cout << s1 << " = " << s2 << endl;
	else
		cout << s1 << " > " << s2 << endl;
	
	// 比较两个C风格字符串
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";

	if (strcmp (ca1, ca2) < 0)
		cout << ca1 << " < " << ca2 << endl;
	else if (strcmp (ca1, ca2) == 0)
		cout << ca1 << " = " << ca2 << endl;
	else
		cout << ca1 << " > " << ca2 << endl;

	return 0;
}

/*

Hello > Halo
A string example > A different string
请按任意键继续. . .

*/
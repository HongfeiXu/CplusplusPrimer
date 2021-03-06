/*
* 练习6.17：编写一个函数，判断 string 对象中是否含有大写字母。编写另一个函数，把 string 对象全部改成小写形式。
*/

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool any_capital (const string &s)
{
	for (auto c : s)
	{
		if (isupper (c))
			return true;
	}
	return false;
}

void to_lowercase (string &s)
{
	for (auto &c : s)	// ? should I set c a reference, Yes, I should.	P61
		c = tolower (c);
}

int main ()
{
	string s = "Hello World!";
	if (any_capital (s))
		cout << "There are some captials in \"" << s << "\"." << endl;
	else
		cout << "There isn't any captials in \"" << s << "\"." << endl;
	to_lowercase (s);
	cout << s << endl;

	return 0;
}


/*

There are some captials in "Hello World!".
hello world!
请按任意键继续. . .

*/
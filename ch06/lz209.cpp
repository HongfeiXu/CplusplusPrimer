/*
* const_cast 和 重载
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int odd[] = { 1, 3, 5, 7, 9 };
int even[] = { 0, 2, 4, 6, 8 };

const string &shorterString (const string &str1, const string &str2)
{
	return str1.size () < str2.size () ? str1 : str2;
}

string &shorterString (string &str1, string &str2)
{
	auto &r = shorterString (const_cast<const string&> (str1), const_cast<const string&> (str2));
	return const_cast<string &>(r);
}

int main ()
{
	string s1 = "Hello";
	string s2 = "Worldd";
	string &s = shorterString (s1, s2);
	cout << s << endl;
	
	return 0;
}

/*

Hello
请按任意键继续. . .

*/
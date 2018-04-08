/*

练习 17.27：编写程序，将九位数字邮政编码的格式转换为 ddddd-dddd

*/

#include <regex>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string pattern = "(\\d{5})([-])?(\\d{4})";
	regex r;
	try
	{
		r = pattern;
	}
	catch(regex_error e)
	{
		cout << e.what() << " " << e.code() << endl;
	}

	string format = "$1-$3";

	string line;
	while (getline(cin, line))
		cout << regex_replace(line, r, format) << endl;

	return 0;
}

/*

123456789
12345-6789
987654321
98765-4321
12345-6789
12345-6789
^Z
请按任意键继续. . .

*/
/*

练习 17.20: 编写你自己版本的验证电话号码的程序。

*/

#include <regex>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool valid(const smatch& m);

int main()
{

	string phone =
		"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	try
	{
		regex r(phone);
		string s;
		while (getline(cin, s))
		{
			for (sregex_iterator it(s.begin(), s.end(), r), end_it;
				 it != end_it; ++it)
			{
				if (valid(*it))
					cout << "valid: " << it->str() << endl;
				else
					cout << "not valid: " << it->str() << endl;
			}
		}
	}
	catch (regex_error e)
	{
		cout << e.what() << "\ncode: " << e.code() << endl;
	}
	
	return 0;
}

bool valid(const smatch& m)
{
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

/*

(151)5422123
valid: (151)5422123
(151) 412-3122
valid: (151) 412-3122
151 123 3211
valid: 151 123 3211
151-123-3211
valid: 151-123-3211
151-123.3211
not valid: 151-123.3211

*/

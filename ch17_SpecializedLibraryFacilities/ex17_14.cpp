/*

练习 17.14：编写几个正则表达式，分别触发不同错误。
运行你的程序，观察编译器对每个错误的输出。

*/

#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	try
	{
		regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
		smatch results;
		string filename;
		while (cin >> filename)
		{
			if (regex_search(filename, results, r))
			{
				cout << results.str() << endl;
			}
		}
	}
	catch (regex_error e){
		cout << e.what() << "code: " << e.code() << endl;
	}

	return 0;
}

/*

regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
regex_error(error_brack): The expression contained mismatched [ and ].code: 4
请按任意键继续. . .

regex r("*[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
regex_error(error_badrepeat): One of *?+{ was not preceded by a valid regular expression.code: 10
请按任意键继续. . .

regex r("[z-a]+\\.(cpp|cxx|cc)$", regex::icase);
regex_error(error_range): The expression contained an invalid character range, such as [b-a] in most encodings.code: 8
请按任意键继续. . .

*/
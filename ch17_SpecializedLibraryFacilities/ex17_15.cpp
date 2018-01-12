/*

练习 17.15：编写程序，使用模式查找违反“i在e之前，除非在c之后”规则的单词。
你的程序应该提示用户输入一个单词，然后指出此单词是否符合要求。用一些违反
和未违反的单词测试你的答案是否正确。

*/

#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string pattern = "[^c]ei";
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	smatch result;
	string word;
	while (cin >> word)
	{
		if (regex_match(word, result, r))
			cout << "\"" << word << "\"" << " is invalid" << endl;
		else
			cout << "\"" << word << "\"" << " is valid" << endl;
	}

	return 0;
}

/*

friend
"friend" is valid
freind
"freind" is invalid
Ceid
"Ceid" is valid
eid
"eid" is valid
eigen
"eigen" is valid
keigen
"keigen" is invalid
kiegen
"kiegen" is valid
^Z
请按任意键继续. . .
*/
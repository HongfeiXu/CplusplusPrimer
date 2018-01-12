/*

练习 17.16：如果前一题程序中的 regex 对象用"[^c]ei"进行初始化，将会发生什么？
用此模式测试你的程序，检查你的答案是否正确。

*/

#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	regex r("[^c]ei", regex::icase);		// 此模式的字符串只包含3个字符，regex_match 的字符串也只能是3个字符，不能match到包含这个模式的整个单词。
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
"freind" is valid
cei
"cei" is valid
aei
"aei" is invalid
aaei
"aaei" is valid
^Z
请按任意键继续. . .

*/
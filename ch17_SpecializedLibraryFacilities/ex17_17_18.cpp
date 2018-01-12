/*

练习 17.17：更新你的程序，令它查找输入队列中所有违反 "ei" 规则的单词

练习 17.18: 修改你的程序，忽略包含 "ei" 但并非拼写错误的单词，如 "albeit" 和 "neighbor"

*/

#include <regex>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<string> ignore_words;	
	ignore_words.insert("albeit");
	ignore_words.insert("neighbor");

	string words;
	getline(cin, words);
	cout << endl;
	cout << "Word(s) that violiate the \"ei\" grammer rule:" << endl;

	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);

	for (sregex_iterator it(words.begin(), words.end(), r), end_it; it != end_it; ++it)
	{
		// 忽略掉合法的单词
		if(ignore_words.find(it->str()) == ignore_words.end())
			cout << it->str() << endl;
	}

	return 0;
}

/*

Happy freind theif albeit feifei neighbor ceicei

Word(s) that violiate the "ei" grammer rule:
freind
theif
feifei
请按任意键继续. . .

*/

/*
*	练习 10.11：编写程序，使用 stable_sort 和 isShorter 将传递给你的 elimDups 版本的 vector 排序。打印 vector 的内容
*	验证程序的正确性。
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());

	words.erase(end_unique, words.end());
}

int main()
{
	vector<string> words { "the", "quick", "red", "aid", "fox", "jumps", "over", "the", "slow", "red", "turtle" };

	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);

	for(auto item : words)
	{
		cout << item << '\n';
	}

	return 0;
}

/*

fox
red
the
over
slow
jumps
queick
turtle
请按任意键继续. . .

*/
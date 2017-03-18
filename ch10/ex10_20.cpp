/*
*	练习 10.20：标准库定义了一个 count_if 算法。使用该算法统计有多少单词长度超过6。
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

vector<string>::size_type bigerThan6(const vector<string> & words)
{
	auto cnt = count_if(words.cbegin(), words.cend(), [](const string &s) {return s.size() > 6; });
	return cnt;
}

int main()
{
	vector<string> words { "the", "quick", "red", "aid", "fox", "jumps", "over", "thesdfadsfa", "slowsdfasdf", "red", "turtle" };

	auto cnt = bigerThan6(words);
	cout << cnt << endl;

	return 0;
}

/*

2
请按任意键继续. . .

*/
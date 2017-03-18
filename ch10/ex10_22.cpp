/*
*	练习 10.20：标准库定义了一个 count_if 算法。使用该算法统计有多少单词长度超过6。
*	练习 10.22：重写统计长度小于等于6的单词数量的程序，使用函数代替 lamdba。
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

bool check_size(const string &s, string::size_type sz)
{
	return s.size() <= sz;
}

vector<string>::size_type bigerThan6(const vector<string> & words)
{
//	auto cnt = count_if(words.cbegin(), words.cend(), [](const string &s) {return s.size() > 6; });
	auto cnt = count_if(words.begin(), words.end(), bind(check_size, placeholders::_1, 6));
	return cnt;
}

int main()
{
	vector<string> words { "thethe", "quickquick", "redred", "aidaid", "foxfox", "jumpsjumps", "overover", "thethe", "slowslow", "redred", "turtleturtle" };

	auto cnt = bigerThan6(words);
	cout << cnt << endl;

	return 0;
}

/*

6
请按任意键继续. . .

*/
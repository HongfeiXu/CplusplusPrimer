/*
*	练习 10.16：使用 lamdba 编写你自己版泵的 biggies。
*	练习 10.18：重写 biggies，用 partition 代替 find_if。
*	练习 10.25：使用 check_size 和 bind 重写 partition()
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());

	words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string& word, const string& ending)
{
	return (ctr > 1) ? word + ending : word;
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

// 消除单词列表中的重复单词，求大于等于给定长度的单词有多少，打印大于等于给定长度的单词
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);

	stable_sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });

//	auto wc2 = partition(words.begin(), words.end(), [sz](const string& s) { return s.size() >= sz; });
	auto wc2 = partition(words.begin(), words.end(), bind(check_size, placeholders::_1, sz));				// 使用 check_size 和 bind 代替 lamdba
	auto count = wc2 - words.begin();
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
	for_each(words.begin(), wc2, [](const string& s) { cout << s << " "; });
	cout << endl;
}

int main()
{
	vector<string> words { "the", "quick", "red", "aid", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	vector<string>::size_type sz = 4;

	biggies(words, sz);

	return 0;
}

/*

5 words of length 4 or longer
turtle quick jumps slow over
请按任意键继续. . .

*/
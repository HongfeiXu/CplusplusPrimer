/*
*	练习 10.16：使用 lamdba 编写你自己版本的 biggies。
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

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

// 消除单词列表中的重复单词，求大于等于给定长度的单词有多少，打印大于等于给定长度的单词
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);

	stable_sort(words.begin(), words.end(), [] (const string& s1, const string& s2) { return s1.size() < s2.size(); });

	auto wc = find_if(words.begin(), words.end(), [sz] (const string& s) { return s.size() >= sz; });

	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;

	for_each(wc, words.end(), [] (const string& s) { cout << s << " "; });
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
over slow jumps quick turtle
请按任意键继续. . .

*/
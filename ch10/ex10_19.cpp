/*
*	练习 10.16：使用 lamdba 编写你自己版泵的 biggies。
*	练习 10.18：重写 biggies，用 partition 代替 find_if。
*	练习 10.19：用 stable_partition 重写前一题程序，与 stable_sort 类似，在划分后的序列中维持原有元素的顺序。
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

	//auto wc = find_if(words.begin(), words.end(), [sz] (const string& s) { return s.size() >= sz; });
	//auto count = words.end() - wc;
	//cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
	//for_each(wc, words.end(), [] (const string& s) { cout << s << " "; });
	//cout << endl;

	//auto wc2 = partition(words.begin(), words.end(), [sz] (const string& s) { return s.size() >= sz; });
	//auto count = wc2 - words.begin();
	//cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
	//for_each(words.begin(), wc2, [] (const string& s) { cout << s << " "; });
	//cout << endl;

	auto wc3 = stable_partition(words.begin(), words.end(), [sz] (const string& s) { return s.size() >= sz; });
	auto count = wc3 - words.begin();
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
	for_each(words.begin(), wc3, [] (const string& s) { cout << s << " "; });
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

//5 words of length 4 or longer
//over slow jumps quick turtle
//请按任意键继续. . .

//5 words of length 4 or longer
//turtle quick jumps slow over			// 注：可以猜测 partition 是采用头插法
//请按任意键继续. . .

5 words of length 4 or longer
over slow jumps quick turtle
请按任意键继续. . .

*/
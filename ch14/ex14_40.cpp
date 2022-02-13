/*
*	练习 10.16：使用 lambda 编写你自己版本的 biggies。
*	练习14.40：重写biggies函数，使用函数对象类替换其中的lambda表达式
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void elimDups(vector<string>& words)
{
	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());

	words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string& word, const string& ending)
{
	return (ctr > 1) ? word + ending : word;
}


// 字符串比较的函数对象
class StringCmp {
public:
	bool operator()(const string& lhs, const string& rhs) const
	{
		return lhs.size() < rhs.size();
	}
};


// 字符串长度是否大于某个数字的函数对象
class LongerString{
public:
	LongerString(size_t _lower_limit) : lower_limit(_lower_limit) { }
	bool operator()(string& str)
	{
		return str.size() >= lower_limit;
	}

private:
	size_t lower_limit{ 0 };
};

// 字符串输出的函数对象
class StringOutput {
public:
	StringOutput(ostream& os_, char sep_) : os(os_), sep(sep_) {}
	void operator()(const string& str)
	{
		os << str << sep;
	}
private:
	ostream& os;
	char sep{ ' ' };
};


// 消除单词列表中的重复单词，求大于等于给定长度的单词有多少，打印大于等于给定长度的单词
void biggies(vector<string>& words, vector<string>::size_type sz)
{
	elimDups(words);

	stable_sort(words.begin(), words.end(), StringCmp());

	auto wc = find_if(words.begin(), words.end(), LongerString(sz));

	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;

	for_each(wc, words.end(), StringOutput(cout, '-'));
	cout << endl;
}

int main()
{
	vector<string> words{ "the", "quick", "red", "aid", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	vector<string>::size_type sz = 4;

	biggies(words, sz);

	return 0;
}

/*

5 words of length 4 or longer
over-slow-jumps-quick-turtle-

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 31624)已退出，代码为 0。
按任意键关闭此窗口. . .

*/
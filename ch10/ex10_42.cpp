/*
	练习 10.42：使用 list 代替 vector 重新实现 10.2.3 节（第 343 页）中的去除重复单词的程序。
*/


#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

void elimDups(list<string> &words)
{
	words.sort();

	words.unique();
}

int main()
{
	list<string> words { "the", "quick", "red", "aid", "fox", "jumps", "over", "the", "slow", "red", "turtle" };

	elimDups(words);

	for(auto item : words)
	{
		cout << item << '\n';
	}

	return 0;
}

/*

aid
fox
jumps
over
quick
red
slow
the
turtle
请按任意键继续. . .

*/

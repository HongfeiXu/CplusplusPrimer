/*
*	练习 10.13：使用 partition 算法，编写函数，接受一个 string，返回一个 bool 值，指出 string 是否含有 5 个或更多字符。
*	使用此函数划分 words。打印出长度大于等于 5 的元素。
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool predict(const string& s)
{
	return s.size() > 4;
}

int main()
{
	vector<string> words { "Micheal", "James", "Kobe", "Alex", "Hongfei" };

	for(auto item : words)
		cout << item << ' ';
	cout << '\n';

	auto iter = partition(words.begin(), words.end(), predict);

	for(auto iter1 = words.cbegin(); iter1 < iter; ++iter1)
	{
		cout << *iter1 << ' ';
	}
	cout << '\n';
	
	return 0;
}

/*

Micheal James Kobe Alex Hongfei
Micheal James Hongfei
请按任意键继续. . .

*/
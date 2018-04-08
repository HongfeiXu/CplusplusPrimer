/*
	向 map 或 multimap 中插入元素 书本 P383
*/


#include <vector>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	map<string, size_t> word_count;

	string word;

	while(cin >> word)
	{
		// 插入一个元素，关键字等于 word，值为 1；
		// 若 word 已经在 word_count 中，insert 什么也不做
		auto ret = word_count.insert({ word, 1 });
		if(!ret.second)				// word 已在 word_count 中
			++ret.first->second;	// 递增计数器
	}

	for(const auto & item : word_count)
		cout << item.first << " " << item.second << endl;
	cout << endl;


	multimap<string, string> authors;
	authors.insert(make_pair("Barth, John", "Sot-Weed Factor"));
	authors.insert(make_pair("Barth, John", "Lost in the Funhouse"));

	for(const auto & item : authors)
		cout << item.first << " " << item.second << endl;
	cout << endl;

	return 0;
}

/*

Hello
Wow
Wow
^Z
Hello 1
Wow 2

Barth, John Sot-Weed Factor
Barth, John Lost in the Funhouse

请按任意键继续. . .

*/
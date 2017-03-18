/*
	练习 11.20：重写 11.1 节练习的单词计数程序，使用 insert 代替下标操作。
	你认为哪个程序更容易编写和阅读？解释原因
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>

using namespace std;

int main()
{
	map<string, size_t> word_count;
	set<string> exclude = { "The", "But", "And", "Or", "An", "A",
		"the", "but", "and", "or", "an", "a" };

	string word;

	while(cin >> word)
	{
		if(exclude.find(word) == exclude.end())
		{
			for(auto &c : word)
			{
				c = static_cast<char> (tolower(c));
			}
			if(ispunct(*(word.end() - 1)))
			{
				word.erase(word.end() - 1);
			}

			// 方法1
			//auto ret = word_count.insert({ word, 1 });
			//if(!ret.second)
			//	++ret.first->second;
			// 方法2
			//++word_count.insert({ word, 0 }).first->second;
			//++word_count[word]; 
		}

	}

	for(const auto &w : word_count)
	{
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times" : " time") << endl;
	}

	return 0;
}

/*

Hello wow wow Woo Hello wow
^Z
hello occurs 2 times
woo occurs 1 time
wow occurs 3 times
请按任意键继续. . .

*/
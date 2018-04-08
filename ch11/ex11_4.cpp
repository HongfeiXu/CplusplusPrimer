/*
	练习 11.3：编写你自己的单词计数程序。
	练习 11.4：扩展你的程序，忽略大小写和标点。例如，"example."、"example," 和 "Example" 应该递增相同的计数器。
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

			++word_count[word];
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

Hello World! Welcome to my New world!
^Z
hello occurs 1 time
my occurs 1 time
new occurs 1 time
to occurs 1 time
welcome occurs 1 time
world occurs 2 times
请按任意键继续. . .

*/

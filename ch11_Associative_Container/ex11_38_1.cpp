/*

练习 11.38：用 unordered_map 重写单词技术程序和单词转换程序。

Part1 单词计数程序

*/


#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	unordered_map<string, size_t> word_count;

	string temp;
	while(cin >> temp)
	{
		++word_count[temp];;
	}

	for(const auto & word : word_count)
	{
		cout << word.first << " occurs " << word.second << (word.second > 1 ? " times" : "time") << endl;
	}

	return 0;
}

/*

Hello wow hi wow hi Hello
^Z
Hello occurs 2 times
wow occurs 2 times
hi occurs 2 times
Press any key to continue . . .

*/
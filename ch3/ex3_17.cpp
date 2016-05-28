#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	vector<string> words;
	string item;
	// 输入
	while (cin >> item)
	{
		words.push_back (item);
	}
	// 处理
	for (auto &word : words)
	{
		for (auto & c : word)
		{
			c = toupper (c);
		}
	}
	// 输出
	for (auto &word : words)
		cout << word << endl;

	return 0;
}

/*

Hello world
^Z
HELLO
WORLD
请按任意键继续. . .

*/
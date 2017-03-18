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
	// ����
	while (cin >> item)
	{
		words.push_back (item);
	}
	// ����
	for (auto &word : words)
	{
		for (auto & c : word)
		{
			c = toupper (c);
		}
	}
	// ���
	for (auto &word : words)
		cout << word << endl;

	return 0;
}

/*

Hello world
^Z
HELLO
WORLD
�밴���������. . .

*/
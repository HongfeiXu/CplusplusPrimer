/*

	练习 11.8：编写一个程序，在一个 vector 而不是 set 中保存不重复的单词。使用 set 的优点是什么？

*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
inline void printContainer(T const &cont)
{
	for(auto item : cont)
	{
		cout << item << " ";
	}
	cout << endl;
}

int main()
{
	vector<string> vecString;
	string word;

	while(cin >> word)
	{
		if(find(vecString.cbegin(), vecString.cend(), word) == vecString.cend())
		{
			vecString.push_back(word);
		}
	}

	printContainer(vecString);

	return 0;
}

/*

Hello World World Wow Hello Bobo
^Z
Hello World Wow Bobo
请按任意键继续. . .

*/
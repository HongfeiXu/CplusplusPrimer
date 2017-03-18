/*

	练习 11.12：编写程序，读入 string 和 int 的序列，将每个 string 和 int 存入一个 pair 中， pair 保存在一个 vector 中。
	练习 11.13：在上一题的程序中，至少有三种创建 pair 的方法。编写此程序中的三个版本。解释你认为那种形式最易于编程和理解。

*/

#include <list>
#include <vector>
#include <string>
#include <map>
#include <utility>

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
	string s;
	int i;
	vector<pair<string, int>> vp;

	while(cin >> s && cin >> i)
	{
		vp.push_back(make_pair(s, i));		// my favorite
	//	vp.push_back(pair<string, int>(s, i));
	//	vp.push_back({ s, i });
	}

	for(const auto & item : vp)
	{
		cout << item.first << " " << item.second << endl;
	}
	
	return 0;
}

/*

Hello 5
Alex 4
Roger 5
^Z
Hello 5
Alex 4
Roger 5
请按任意键继续. . .

*/
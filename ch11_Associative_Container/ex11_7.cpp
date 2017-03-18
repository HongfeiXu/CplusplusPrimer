/*

	练习 11.7：定义一个 map，关键字是家庭的姓，值是一个 vector，保存家中孩子（们）的名。
	编写程序，实现添加新的家庭以及向已有家庭中添加新的孩子。

*/

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	map<string, vector<string>> familyNames;

	string firstName, lastName;

	while(cin >> firstName)
	{
		cin >> lastName;
		familyNames[lastName].push_back(firstName);
	}

	for(const auto & w : familyNames)
	{
		cout << w.first << ":"<< endl;
		for(decltype(w.second.size()) i = 0; i < w.second.size(); ++i)
		{
			cout << w.second[i] << " " << w.first << endl;
		}
	}

	return 0;
}

/*

Bobo Zhu
Hongfei Xu
Qi Zhu
Liangdong Xu
^Z
Xu:
Hongfei Xu
Liangdong Xu
Zhu:
Bobo Zhu
Qi Zhu
请按任意键继续. . .

*/
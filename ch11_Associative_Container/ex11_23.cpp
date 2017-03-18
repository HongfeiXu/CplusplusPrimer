/*
	练习 11.23：11.2.1 节练习中的 map 以孩子的姓为关键字，保存他们的名的 vector，用 multimap 重写此 map。
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cctype>

using namespace std;

int main()
{
	multimap<string, string> family;

	string fstName, lastName;

	
	while(cin >> fstName && cin >> lastName)
	{
		family.insert({ lastName, fstName });
	}

	for(const auto & item : family)
	{
		cout << item.second << " " << item.first << endl;
	}

	return 0;
}

/*

Roger Alex
Bobo Alex
Hongfei Xu
Bobo Zhu
^Z
Roger Alex
Bobo Alex
Hongfei Xu
Bobo Zhu
请按任意键继续. . .

*/
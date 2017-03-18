/*
* 练习 9.19：重写上题程序，用 list 替代 deque。列出程序要做出哪些改变。
*/

#include <iostream>
#include <string>
#include <deque>
#include <list>

using namespace std;

int main()
{
//	deque<string> ds;
	list<string> ls;
	string word;
	while(cin >> word)
	{
		ls.push_back(word);
	}
	for(string str; cin >> str; ls.push_back(str));

	for(auto iter = ls.cbegin(); iter != ls.cend(); ++iter)
		cout << *iter << " ";
	cout << endl;

	return 0;
}


/*

Hello World , I am Alex .
^Z
Hello World , I am Alex .
请按任意键继续. . .

*/
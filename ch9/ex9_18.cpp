/*
* 练习 9.18：编写程序，从标准输入读取 string 序列，存入一个 deque 中。编写一个循环，用迭代器打印 deque 中的元素。
*/

#include <string>
#include <iostream>
#include <deque>

using namespace std;

int main()
{
	string word;
	deque<string> ds;
	while(cin >> word)
	{
		ds.push_back(word);
	}

	for(auto iter = ds.cbegin(); iter != ds.cend(); ++iter)
		cout << *iter << " ";
	cout << endl;

	return 0;
}


/*

Hello World. I am Alex.
^Z
Hello World. I am Alex.
请按任意键继续. . .

*/
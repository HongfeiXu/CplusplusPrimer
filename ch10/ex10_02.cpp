/*
*	练习 10.1：编写程序，读取 int 序列存入 vector 中，打印有多少个元素的值等于给定值。
*	练习 10.2：重做上一题，但是读取 string 序列存入 list 中。
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <sstream>

using namespace std;

int main()
{
	string temp;
	list<string> ls;
	
	int targetNumber = 23;
	string targetString;

	stringstream tempStream;		// 为了 itoa
	tempStream << targetNumber;

	targetString = tempStream.str();

	while(cin >> temp)
	{
		ls.push_back(temp);
	}

	auto number = count(ls.cbegin(), ls.cend(), targetString);
	cout << "There are " << number << " '23'.\n";

	return 0;
}

/*

12 2 3 23 34 23 434 23
^Z
There are 3 '23'.
请按任意键继续. . .

*/
/*
* 练习 9.25
*/

#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> iv;
	list<int> il;
	
	for(auto item : ia)
	{
		iv.push_back(item);
		il.push_back(item);
	}

	auto iter = iv.begin();
	while(iter != iv.end())
	{
		if(*iter % 2)
			iter = iv.erase(iter);
		else
			++iter;
	}
	for(auto item : iv)
		cout << item << " ";
	cout << endl;

	auto iter2 = il.begin();		
	while(iter2 != il.end())
	{
		if(*iter2 % 2 == 0)
			iter2 = il.erase(iter2);
		else
			++iter2;
	}
	for(auto item : il)
		cout << item << " ";
	cout << endl;

	return 0;
}

/*

0 2 8
1 1 3 5 13 21 55 89
请按任意键继续. . .

*/
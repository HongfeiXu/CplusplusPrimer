/*
* 练习 9.20：编写程序，从一个 list<int> 拷贝元素到两个 deque 中。值为偶数的所有元素都拷贝到一个 deque 中，
* 而奇数值元素都拷贝到另一个 deque 中。
*/

#include <iostream>
#include <deque>
#include <list>

using namespace std;

int main()
{
	list<int> nums = { 1, 2, 3, 4, 6, 6, 7, 8 };
	deque<int> odds;
	deque<int> evens;

	for(auto item : nums)
	{
		if(item % 2 == 0)
			evens.push_back(item);
		else
			odds.push_back(item);
	}

	for(auto item : odds)
		cout << item;
	cout << endl;

	for(auto item : evens)
		cout << item;
	cout << endl;

	return 0;
}


/*

137
24668
请按任意键继续. . .

*/
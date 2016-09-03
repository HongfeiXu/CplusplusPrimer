/*
* 练习 9.25
*/

#include <list>
#include <iostream>

using std::list;
using std::cout;
using std::endl;

int main()
{
	list<int> lst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto elem1 = lst.begin();
	auto elem2 = lst.begin();

	elem1 = lst.erase(elem1, elem2);		// 0123456789
	for(auto item : lst)
		cout << item;
	cout << endl;

	elem1 = lst.end();
	elem2 = lst.end();
	elem1 = lst.erase(elem1, elem2);		// 0123456789
	for(auto item : lst)
		cout << item;
	cout << endl;


	return 0;
}

/*

1 3 5 7 9
请按任意键继续. . .

*/
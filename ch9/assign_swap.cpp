/*
* assign 和swap
*/
#include <array>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>

#include <iostream>

using std::array;
using std::vector;
using std::string;
using std::list;
using std::forward_list;
using std::deque;

using std::cout;
using std::endl;


int main()
{
	array<int, 3> a1 = {1, 2, 3};
	array<int, 3> a2 = { 0, 2, 3};
	for(auto item : a2)
		cout << item << " ";
	cout << endl;

	a2 = { 1 };		// 相当于 a2 = {1, 0, 0, 0};
	for(auto item : a2)
		cout << item << " ";
	cout << endl;
		
	swap(a1, a2);	// 交换 a2, a1 中的元素
	for(auto item : a2)
		cout << item << " ";
	cout << endl;

	a2.assign(3);	// 将 a2 中元素全部替换为 3
	for(auto item : a2)
		cout << item << " ";
	cout << endl << endl;

	list<int> l1 = { 1, 2, 3, 4 };
	list<double> l2 = { 1.0, 2.0, 3.0 };
	l2.assign(l1.cbegin(), l1.cend());	// 将 l2 中的元素替换为迭代器所表示范围中的元素
	for(auto item : l2)
		cout << item << " ";
	cout << endl;

	l1.assign(l2.cbegin(), l2.cend());
	for(auto item : l1)
		cout << item << " ";
	cout << endl;

	l1.assign(5, 1);	// 将 l1 中元素替换为 5 个值为 1 的元素
	for(auto item : l1)
		cout << item << " ";
	cout << endl;

	vector<const char*> oldstyle = {"Hello", "World"};
	list<string> names;

	//names = oldstyle; // 容器类型不匹配
	names.assign(oldstyle.cbegin(), oldstyle.cend());	// 用另一个容器中的一个子序列赋值这个容器，只要其元素可以合法转换。 此处 const char * 可以转换为 string
	for(auto item : names)
		cout << item << " ";
	cout << endl;

	list<string> slist1(1);
	slist1.assign(10, "Hiya!");
	for(auto item : slist1)
		cout << item << " ";
	cout << endl;

	return 0;
}


/*

0 2 3
1 0 0
1 2 3
3 3 3

1 2 3 4
1 2 3 4
1 1 1 1 1
Hello World
Hiya! Hiya! Hiya! Hiya! Hiya! Hiya! Hiya! Hiya! Hiya! Hiya!
请按任意键继续. . .

*/
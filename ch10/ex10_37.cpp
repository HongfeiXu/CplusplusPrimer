/*
	练习 10.37：给定一个包含 10 个元素的 vector，将位置 3 到 7 之间的元素按逆序拷贝到一个 list 中。
*/

#include <vector>
#include <list>
#include <iostream>
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
	vector<int> vecInt { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> lstInt;

	lstInt.assign(vecInt.crbegin() + 3, vecInt.crbegin() + 7);

	printContainer(vecInt);
	printContainer(lstInt);

	return 0;
}

/*

0 1 2 3 4 5 6 7 8 9
6 5 4 3
请按任意键继续. . .

*/
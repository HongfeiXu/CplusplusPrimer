/*
练习 10.34：使用 reverse_iterator 逆序打印一个vector。
练习 10.35：使用普通迭代器逆序打印一个 vector。
*/

#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> vecInt { 1,2,3,4,5 };

	for(auto r_iter = vecInt.crbegin(); r_iter != vecInt.crend(); r_iter++)
		cout << *r_iter << " ";
	cout << endl;

	vector<int>::const_iterator iter;
	for(iter = vecInt.cend() - 1; iter != vecInt.cbegin(); iter--)
		cout << *iter << " ";
	cout << *iter << endl;

	return 0;
}

/*

5 4 3 2 1
5 4 3 2 1
请按任意键继续. . .

*/
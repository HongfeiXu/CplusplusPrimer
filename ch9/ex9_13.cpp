/*
* 练习 9.13：如何从一个 list<int> 初始化一个 vector<double>？从一个 vector<int> 又该如何创建？
*/
#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::cout;
using std::endl;

void printVector(const vector<double> &v);


int main()
{
	list<int> li = { 1, 2, 3, 4, 5 };
	vector<int> vi = { 2, 3, 4, 5, 6 };

	vector<double> vd(li.cbegin(), li.cend());
	vector<double> vd2(vi.cbegin(), vi.cend());

	printVector(vd);
	printVector(vd2);
	
	return 0;
}

void printVector(const vector<double> &v)
{
	cout << "Vector: ";
	for(auto item : v)
	{
		cout << item << " ";
	}
	cout << endl;
}

/*

Vector: 1 2 3 4 5
Vector: 2 3 4 5 6
请按任意键继续. . .

*/
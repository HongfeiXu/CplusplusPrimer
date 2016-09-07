/*
* 练习 9.31：删除偶数元素，复制每个奇数元素。修改程序，使之能用于 list 和 forward_list。
*/

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

void printList(list<int> &ilst);
void printVector(vector<int> &iv);

int main()
{
	vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto iter = vi.begin();
	while(iter != vi.end())
	{
		if(*iter % 2)
		{
			iter = vi.insert(iter, *iter);
			iter += 2;
		}
		else
		{
			iter = vi.erase(iter);
		}
	}
	printVector(vi);

	list<int> li = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto iter1 = li.begin();
	while(iter1 != li.end())
	{
		if(*iter1 % 2)
		{
			iter1 = li.insert(iter1, *iter1);
			advance(iter1, 2);
		}
		else
		{
			iter1 = li.erase(iter1);
		}
	}
	printList(li);

	forward_list<int> fli = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto prev = fli.before_begin();
	auto curr = fli.begin();
	while(curr != fli.end())
	{
		if(*curr % 2)
		{
			prev = fli.insert_after(prev, *curr);
			prev++;
			curr++;
		}
		else
		{
			curr = fli.erase_after(prev);
		}
	}
	printList(li);

	return 0;
}

void printList(list<int> &ilst)
{
	for(auto item : ilst)
		cout << item << " ";
	cout << endl;
}

void printVector(vector<int> &iv)
{
	for(auto item : iv)
		cout << item << " ";
	cout << endl;
}

/*

1 1 3 3 5 5 7 7 9 9
1 1 3 3 5 5 7 7 9 9
1 1 3 3 5 5 7 7 9 9
请按任意键继续. . .

*/
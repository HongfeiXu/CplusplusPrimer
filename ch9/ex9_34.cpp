/*
* 练习 9.34：假定 vi 是一个保存 int 的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &iv);

int main()
{
	vector<int> vi = { 23, 1, 10, 6, 24, 11 };
	for(auto iter = vi.begin(); iter != vi.end(); ++iter)
	{
		if(*iter % 2)
		{
			iter = vi.insert(iter, *iter);
			++iter;
		}
	}
	printVector(vi);

	return 0;
}

void printVector(vector<int> &iv)
{
	for(auto item : iv)
		cout << item << " ";
	cout << endl;
}

/*

23 23 1 1 10 6 24 11 11
请按任意键继续. . .

*/
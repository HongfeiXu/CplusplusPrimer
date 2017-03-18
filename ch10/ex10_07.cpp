/*
*	练习 10.7
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
	vector<int> vec;
	list<int> lst;
	int i;
	while(cin >> i)
	{
		lst.push_back(i);
	}

	vec.resize(lst.size());	// 改变容器中元素的数目
	// 在 copy 之前需要给 vec 分配足够大的空间用来存储输入序列
	// 因为，传递个 copy 的目标序列至少要包含与输入序列一样多的元素

	copy(lst.cbegin(), lst.cend(), vec.begin());

	for(auto elem : vec)
	{
		cout << elem << ' ';
	}
	cout << '\n';

	vector<int> v;

	//v.reserve(10);
	v.resize(10);

	fill_n(v.begin(), 10, 0);
	for(auto elem : v)
	{
		cout << elem << ' ';
	}
	cout << '\n';

	return 0;
}

/*

1 2 3 4 5
^Z
1 2 3 4 5
0 0 0 0 0 0 0 0 0 0
请按任意键继续. . .

*/
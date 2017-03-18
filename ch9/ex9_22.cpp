/*
* 练习 9.22： 修改程序
we may interpret author's original abstraction intention in two different ways:

mid refereed to the initial middle index permanently.
mid refereed to the dynamic middle index that would change when a new item was inserted into first half of the container.

我选择第一种理解方式
*/

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> iv = { 0, 1, 2, 2, 4, 5, 6, 2, 8, 9 };
	for(auto item : iv)
		cout << item << " ";
	cout << endl;

	vector<int>::iterator iter = iv.begin();
	vector<int>::iterator mid = iv.begin() + iv.size() / 2;


	while(iter != mid)
	{
		if(*iter == 2)
		{
			iter = iv.insert(iter, 2 * 2);		// iter 指向新插入的元素（因为插入后 iter 失效，所以不能直接 iter++）
			iter += 1;		// 跳过刚插入的元素，指向本来的元素
			mid = iv.begin() + (iv.size() - 1) / 2 + 1;	// 因为插入后mid失效，这里重新让 mid 指向原来的中间元素 也就是 5
		}
		++iter;	// 向后移动一个元素
	}

	for(auto item : iv)
		cout << item << " ";
	cout << endl;

	return 0;
}

/*

0 1 2 2 4 5 6 2 8 9
0 1 4 2 4 2 4 5 6 2 8 9
请按任意键继续. . .

*/
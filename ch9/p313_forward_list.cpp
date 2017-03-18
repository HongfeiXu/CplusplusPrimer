/*
* p313 删除 forward_list 中的奇数元素
* 当在 forward_list 中添加或删除元素时，我们必须关注两个迭代器，一个指向我们要处理的元素，另一个指向其前驱。
*/

#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
	forward_list<int> flst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto prev = flst.before_begin();		// 指向要处理元素的前驱
	auto curr = flst.begin();				// 指向我们要处理的元素

	while(curr != flst.end())
	{
		if(*curr % 2)
		{
			curr = flst.erase_after(prev);	// curr 指向下一个元素
		}
		else
		{
			prev = curr;
			++curr;
		}
	}

	for(auto item : flst)
		cout << item << " ";
	cout << endl;

	return 0;
}

/*

0 2 4 6 8
请按任意键继续. . .

*/
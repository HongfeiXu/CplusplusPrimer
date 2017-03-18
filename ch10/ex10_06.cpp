/*
*	练习 10.6：编写程序，使用 fill_n 将一个序列中所有的 int 值都设置为 0
*/

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::vector<int> iVec { 1,2,3,4 };

	for(auto item : iVec)
	{
		std::cout << item << ' ';
	}
	std::cout << '\n';

	fill_n(iVec.begin(), iVec.size(), 0);

	for(auto item : iVec)
	{
		std::cout << item << ' ';
	}
	std::cout << '\n';

	return 0;
}

/*

1 2 3 4
0 0 0 0
请按任意键继续. . .

*/
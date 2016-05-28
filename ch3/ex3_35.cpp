/*
* 练习3.35 编写一段程序，利用指针将数组中的元素置为0。
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main ()
{
	constexpr size_t sz = 5;
	int arr[sz] = { 1, 2, 3, 4, 5 };
	int *beg = arr;
	int *end = arr + sz;
	while (beg != end)
	{
		*beg = 0;
		++beg;
	}
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
		
	return 0;
}

/*

0 0 0 0 0
请按任意键继续. . .

*/
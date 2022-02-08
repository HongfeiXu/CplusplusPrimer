/*
练习 16.62：定义你自己版本的 hash<Sales_data>, 并定义一个 Sales_data 对象的 unorder_multise。将多条交易记录保存到容器中，并打印其内容。
*/

#include "Sales_data.h"
#include <unordered_set>

int main()
{
	std::unordered_multiset<Sales_data> us;
	us.insert(Sales_data{ "Book", 10, 1000 });
	us.insert(Sales_data{ "Book", 10, 1000 });
	us.insert(Sales_data{ "Water", 1000, 1 });
	for (auto it = us.cbegin(); it != us.cend(); ++it)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}

/*

Book 10 10000 1000
Book 10 10000 1000
Water 1000 1000 1

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 58568)已退出，代码为 0。
按任意键关闭此窗口. . .

*/
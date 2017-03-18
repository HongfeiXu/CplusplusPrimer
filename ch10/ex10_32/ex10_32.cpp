/*
	练习 10.32：重写1.6节中的书店程序，使用一个 vector 保存交易记录，使用不同的算法完成处理。
	使用 sort 和 10.3.1 节中的 compareIsbn 函数来排序交易记录，然后用 find 和 accumulate 求和。
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iterator>
#include <cassert>
#include <numeric>		// accumulate
#include "Sales_item.h"

using namespace std;

template <typename T>
inline void printContainer(T const &cont)
{
	for(auto item : cont)
	{
		cout << item << endl;
	}
}

int main()
{
	ifstream infile("book_sales");
	assert(infile);

	istream_iterator<Sales_item> item_iter(infile), eof;
	ostream_iterator<Sales_item> out_iter(cout, "\n");

	vector<Sales_item> vecSalesItem;

	while(item_iter != eof)
	{
		vecSalesItem.push_back(*item_iter++);
	}

	cout << "Before sort:\n";
	printContainer(vecSalesItem);
	cout << endl;
	sort(vecSalesItem.begin(), vecSalesItem.end(), compareIsbn);
	cout << "After sort:\n";
	printContainer(vecSalesItem);
	cout << endl;

	cout << "Accumulate:\n";
	for(auto beg = vecSalesItem.cbegin(), end = beg; beg != vecSalesItem.cend(); beg = end)
	{
		end = find_if(beg, vecSalesItem.cend(), [beg] (const Sales_item &item) { return item.isbn() != beg->isbn(); });
		std::cout << std::accumulate(beg, end, Sales_item(beg->isbn())) << endl;		// 使用构造函数 Sales_item(const std::string &book): 构造一个数值为0，bookNo 相同的对象，然后与其他对象相加
	}
	infile.close();
	return 0;
}

/*

Before sort:
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 2 30 15
0-201-88954-4 5 60 12
0-201-88954-4 7 84 12
0-201-88954-4 2 24 12
0-399-82477-1 2 90.78 45.39
0-399-82477-1 3 136.17 45.39
0-201-78345-X 3 60 20
0-201-78345-X 2 50 25

After sort:
0-201-70353-X 4 99.96 24.99
0-201-78345-X 3 60 20
0-201-78345-X 2 50 25
0-201-82470-1 4 181.56 45.39
0-201-88954-4 2 30 15
0-201-88954-4 5 60 12
0-201-88954-4 7 84 12
0-201-88954-4 2 24 12
0-399-82477-1 2 90.78 45.39
0-399-82477-1 3 136.17 45.39

Accumulate:
0-201-70353-X 4 99.96 24.99
0-201-78345-X 5 110 22
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
请按任意键继续. . .

*/
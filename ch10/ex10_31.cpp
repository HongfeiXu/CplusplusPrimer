/*

练习 10.30：使用流迭代器、sort 和 copy 从标准输入读取一个整数序列，将其排序并将结果写到标准输出。

练习 10.31：修改前一题程序，使其只打印不重复的元素。你的程序使用 unique_copy。

*/

#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename T>
inline void printContainer(T const &cont)
{
	for(auto item : cont)
	{
		cout << item << " ";
	}
	cout << endl;
}


int main()
{
	istream_iterator<int> ii(cin), eof;

	vector<int> vecI;

	while(ii != eof)
	{
		vecI.push_back(*ii++);
	}

	ostream_iterator<int> oi(cout, " ");

	sort(vecI.begin(), vecI.end());
	unique_copy(vecI.begin(), vecI.end(), oi);
	cout << endl;

	return 0;
}

/*

-9 1 9 1 23 -10 10 -10 1 5
^Z
-10 -9 1 5 9 10 23
请按任意键继续. . .

*/
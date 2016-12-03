/*

练习 10.30：使用流迭代器、sort 和 copy 从标准输入读取一个整数序列，将其排序并将结果写到标准输出。

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
	copy(vecI.begin(), vecI.end(), oi);
	cout << endl;

	return 0;
}

/*

1 -9 29 80 9 76 -3
^Z
-9 -3 1 9 29 76 80
请按任意键继续. . .

*/
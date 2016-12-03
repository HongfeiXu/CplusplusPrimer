/*

练习 10.29：编写程序，使用流迭代器读取一个文本文件，存入一个 vector 中的 string 里。

*/

#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
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
	ifstream infile("afile.txt");
	assert(infile);

	istream_iterator<string> in(infile), eof;

	vector<string> vecStr(in, eof);

	printContainer(vecStr);

	return 0;
}

/*

What's in a name? That which we call a rose By any other name would smell as sweet.
请按任意键继续. . .

*/
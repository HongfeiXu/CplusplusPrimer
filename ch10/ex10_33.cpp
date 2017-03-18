/*

练习 10.33：编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。输入文件保存的应该是整数。
使用 istream_iterator 读取输入文件。使用 ostream_iterator 将奇数写入第一个输出文件，每个值之后都跟一个空格。
将偶数写入第二个输出文件，每个值都独占一行。

*/

#include <iostream>
#include <fstream>
#include <iterator>
#include <cassert>

using namespace std;

int main()
{
	ifstream inFile("Numbers.dat");
	assert(inFile);

	ofstream outFile1("OddNumbers.dat");
	ofstream outFile2("EvenNumbers.dat");
	

	istream_iterator<int> ii(inFile), eof;
	ostream_iterator<int> oi1(outFile1, " ");
	ostream_iterator<int> oi2(outFile2, "\n");

	while(ii != eof)
	{
		if(*ii % 2 == 1)
		{
			*oi1++ = *ii++;
		}
		else
		{
			*oi2++ = *ii++;
		}
	}

	outFile1.close();
	outFile2.close();

	return 0;
}


/*

Contents in Numbers.dat:

1 2 3 4 5 6 19 0 -2 39 12 18 182 13
31 22 88

Contents in OddNumbers.dat:

1 3 5 19 39 13 31

Contents in EvenNumbers.dat:

2
4
6
0
-2
12
18
182
22
88


*/
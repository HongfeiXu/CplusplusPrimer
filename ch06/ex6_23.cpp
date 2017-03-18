/*
* 练习6.23：参考本节介绍的几个print函数，根据理解编写你自己的版本。
* 依次调用每个函数使其输入下面定义的 i 和 j；
* int i = 0, j[2] = {0, 1};
*/

#include <iostream>
#include <iterator>

using std::begin;
using std::end;
using std::cout;
using std::cin;
using std::endl;

void print (const char *cp)
{
	if (cp)
		while (*cp)
			cout << *cp++;
	cout << endl;
}

void print (const int *pi)
{
	if (pi)
		cout << *pi << endl;
}

void print (const int *beg, const int *end)
{
	while (beg != end)
	{
		cout << *beg++;
	}
	cout << endl;
}

void print (const int ia[], size_t size)
{
	for (size_t i = 0; i != size; ++i)
	{
		cout << ia[i];
	}
	cout << endl;
}

void print (int (&a)[2])
{
	for (auto elem : a)
	{
		cout << elem;
	}
	cout << endl;
}

int main ()
{
	int i = 0, j[2] = { 0, 1 };
	char ch[5] = "Alex";
	print (ch);
	print (&i);
	print (begin (j), end(j));
	print (j, end (j) - begin (j));
//	print (j);		// 有多个重载与参数列表匹配。

	return 0;
}


/*

Alex
0
01
01
请按任意键继续. . .

*/
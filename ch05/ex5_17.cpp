/*
* 练习5.17：假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。
*/

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main ()
{
	vector<int> v1 = { 0, 1, 1, 2 };
	vector<int> v2 = { 0, 1, 1, 2, 3, 5, 8 };
	if (v1.size () < v2.size ())
	{
		decltype(v1.size ()) index = 0;
		for ( ; index != v1.size() && v1[index] == v2[index]; ++index)
			;
		if (index == v1.size ())
			cout << "v1 is the prefix of v2 " << endl;
		else
			cout << "v1 is not the prefix of v2" << endl;
	}
	else
	{
		decltype(v1.size ()) index = 0;
		for (; index != v2.size () && v1[index] == v2[index]; ++index)
			;
		if (index == v2.size ())
			cout << "v2 is the prefix of v1" << endl;
		else
			cout << "v2 is not the prefix of v1" << endl;
	}


	return 0;
}

/*

v1 is the prefix of v2
请按任意键继续. . .
*/
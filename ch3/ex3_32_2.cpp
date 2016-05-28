/*
* 练习3.32_2：编写一段程序，定义一个含有10个int的数组，令每个元素的值都是其下标值。
* 将创建的数组拷贝给另外一个数组。
* 利用vecotr重写程序，实现类似的功能。
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	vector<int> iv;
	for (int i = 0; i < 10; i++)
		iv.push_back (i);
	cout << "iv:" << endl;
	for (vector<int>::size_type i = 0; i != 10; i++)
		cout << iv[i] << " ";
	cout << endl;

	vector<int> iv_2;
	for (vector<int>::size_type i = 0; i != 10; i++)
		iv_2.push_back (iv[i]);
	cout << "iv_2" << endl;
	for (vector<int>::size_type i = 0; i != 10; i++)
		cout << iv_2[i] << " ";
	cout << endl;
		
	return 0;
}

/*

iv:
0 1 2 3 4 5 6 7 8 9
iv_2
0 1 2 3 4 5 6 7 8 9
请按任意键继续. . .

*/
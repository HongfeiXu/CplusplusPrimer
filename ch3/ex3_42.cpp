/*
* 练习3.42：编写一段程序，将含有整数元素的vector对象拷贝给一个整型数组。
*/

#include <iostream>
#include <iterator>
#include <vector>

using std::vector;
using std::begin;
using std::end;
using std::cout;
using std::cin;
using std::endl;


int main ()
{
	constexpr size_t sz = 5;
	vector<int> iv;
	for (size_t i = 0; i < sz; i++)
		iv.push_back (i);
	cout << "vector iv:" << endl;
	for (auto i : iv)
		cout << i << " ";
	cout << endl;
	int arr[sz];
	for (size_t i = 0; i < sz; i++)
		arr[i] = iv[i];
	cout << "array arr:" << endl;
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
		
	return 0;
}

/*

vector iv:
0 1 2 3 4
array arr:
0 1 2 3 4
请按任意键继续. . .

*/
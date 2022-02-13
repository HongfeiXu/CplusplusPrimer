/*

练习14.43
使用标准库函数对象判断一个给定的int值是否能被 int 容器中的所有元素整除。

*/

#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> ivec{ 2,3,5 };
	int input;
	cin >> input;

	modulus<int> intMod;	// 求余
	auto predicator = [&](int i) { return 0 == intMod(input, i); };
	
	bool result = all_of(ivec.cbegin(), ivec.cend(), predicator);
	cout << boolalpha << result << endl;

	return 0;
}

/*
30
true

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 25100)已退出，代码为 0。
按任意键关闭此窗口. . .
*/


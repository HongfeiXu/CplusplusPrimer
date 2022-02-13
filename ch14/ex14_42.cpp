/*

练习14.42
使用标准库函数对象及适配器定义一条表达式，令其

(a) 统计大于1024的值有多少个。
(b) 找到第一个不等于pooh的字符串。
(c)将所有的值乘以2。

*/

#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> ivec{ 1,2,3,4104,32211 };
	auto count = count_if(ivec.cbegin(), ivec.cend(), bind(greater<int>(), placeholders::_1, 1024));
	std::cout << count << std::endl;

	vector<string> svec{ "pooh", "fuu", "pooh" };
	auto it = find_if(svec.cbegin(), svec.cend(), bind(not_equal_to<string>(), placeholders::_1, string("pooh")));
	if (it != svec.cend())
	{
		cout << *it << endl;
	}

	for_each(ivec.cbegin(), ivec.cend(), [](int i) {cout << i << " "; });
	cout << "\n";
	transform(ivec.begin(), ivec.end(), ivec.begin(), bind(multiplies<int>(), placeholders::_1, 2));
	for_each(ivec.cbegin(), ivec.cend(), [](int i) {cout << i << " "; });

	return 0;
}

/*

2
fuu
1 2 3 4104 32211
2 4 6 8208 64422
E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 35416)已退出，代码为 0。
按任意键关闭此窗口. . .

*/


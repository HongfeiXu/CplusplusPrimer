/*

时间测量
使用 C++11 中的 chrono 库

http://en.cppreference.com/w/cpp/chrono/duration/duration_cast

*/

#include <chrono>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;

	auto t0 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 10000; ++i)
	{
		v.push_back(i);
	}

	auto t1 = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << "ms\n";

	return 0;
}

/*

6ms
请按任意键继续. . .

*/


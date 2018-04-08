/*

练习 17.28：编写函数，每次调用生成并返回一个均匀分布的随机 unsigned int
练习 17.29：修改上一题中编写的函数，允许用户提供一个种子作为可选参数
练习 17.30：再次修改你的程序，此次再添加两个参数，表示函数允许返回的最小值和最大值

*/

#include <random>
#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>

using namespace std;

unsigned int randNum()
{
	static default_random_engine e(time(0));
	static uniform_int_distribution<unsigned int> u(0, 9);
	return u(e);
}

unsigned int randNumWithSeed(int seed)
{
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned int> u(0, 9);
	return u(e);
}

unsigned int randNumWithSeedAndGap(int seed, int min, int max)
{
	assert(min <= max);
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned int> u(min, max);

	return u(e);
}

int main()
{
	cout << randNum() << endl;
	cout << randNumWithSeed(23) << endl;
	cout << randNumWithSeedAndGap(23, 7, 17) << endl;

	return 0;
}

/*

8
1
17
请按任意键继续. . .

*/

/*

练习 17.10：使用序列 1,2,3,5,8,13,21 初始化一个 bitset ，将这些位置置位。
对另一个 bitset 进行默认初始化，并编写一段程序将其恰当位置置位。

*/

#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec = { 1,2,3,5,8,13,21 };
	bitset<32> bitvec;
	
	for_each(vec.begin(), vec.end(), [&bitvec](int pos) { bitvec.set(pos); });
	cout << bitvec << endl;

	bitset<32> bitvec2;
	for (int i = 0; i < 32; i += 2)
		bitvec2.set(i);
	cout << bitvec2 << endl;

	return 0;
}

/*

00000000001000000010000100101110
01010101010101010101010101010101
请按任意键继续. . .

*/
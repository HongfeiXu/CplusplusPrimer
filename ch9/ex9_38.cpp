/*
* 练习 9.39：编写程序，探究在你的标准库实现中，vector是如何增长的。
* 没有看出来啥规律。
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	auto oldCapacity = ivec.capacity();

	for(int i = 1; i <= 100; i++)
	{
		ivec.push_back(i);
		if(ivec.capacity() != oldCapacity)		// 当 capacity 变化的时候输处 size 和 capacity
		{
			cout << "ivec: size: " << ivec.size()
				<< " capacity: " << ivec.capacity() << endl;
			oldCapacity = ivec.capacity();
		}
		
	}


	return 0;
}

/*

ivec: size: 0 capacity: 0
ivec: size: 1 capacity: 1
ivec: size: 2 capacity: 2
ivec: size: 3 capacity: 3
ivec: size: 4 capacity: 4
ivec: size: 5 capacity: 6
ivec: size: 7 capacity: 9
ivec: size: 10 capacity: 13
ivec: size: 14 capacity: 19
ivec: size: 20 capacity: 28
ivec: size: 29 capacity: 42
ivec: size: 43 capacity: 63
ivec: size: 64 capacity: 94
ivec: size: 95 capacity: 141
请按任意键继续. . .

*/
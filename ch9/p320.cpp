#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	ivec.reserve(50);
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	while (ivec.size() != ivec.capacity())
	{
		ivec.push_back(0);
	}
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	ivec.push_back(42);
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	ivec.shrink_to_fit();
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	return 0;
}

/*

ivec: size: 0 capacity: 0
ivec: size: 24 capacity: 28
ivec: size: 24 capacity: 50
ivec: size: 50 capacity: 50
ivec: size: 51 capacity: 75
ivec: size: 51 capacity: 51
请按任意键继续. . .

*/
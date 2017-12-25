/*

练习 17.9：解释下列每个 bitset 对象所包含的位模式

*/

#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	bitset<64> bitvec(32);
	cout << bitvec << endl;

	bitset<32> bitvec2(1010101);
	cout << bitvec2 << endl;

	string bstr;
	cin >> bstr;
	bitset<8> bitvec3(bstr);
	cout << bitvec3 << endl;


	return 0;
}

/*

0000000000000000000000000000000000000000000000000000000000100000
00000000000011110110100110110101
10101010
10101010
请按任意键继续. . .

0000000000000000000000000000000000000000000000000000000000100000
00000000000011110110100110110101
1111111100000000
11111111
请按任意键继续. . .

*/
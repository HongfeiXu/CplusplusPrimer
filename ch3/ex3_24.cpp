/*
* ��ϰ3.24��ʹ�õ�����������ϰ3.20��
* ����һ���������������Ǵ���һ��vector���󣬽�ÿ�����������ĺ����������
* ��д��ĳ������Ҫ���������1�������1��Ԫ�صĺͣ����������2���͵�����2��Ԫ�صĺͣ��Դ����ơ�
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	vector<int> v;
	for (int item; cin >> item; v.push_back (item));
	for (auto beg = v.cbegin (); beg != v.cend () - 1; ++beg)		// begһֱ��vector�ĵ�����2��Ԫ��
		cout << *beg + *(beg + 1) << " ";		// ����ǰԪ�������ڵ�Ԫ�����
	cout << endl;
	auto mid = v.cbegin () + (v.cend () - v.cbegin ()) / 2;
	for (auto beg = v.cbegin (); beg < mid; ++beg)		// �������1�������1��Ԫ�صĺͣ����������2���͵�����2��Ԫ�صĺ�
	{
		cout << *beg + *(v.cend () - 1 - (beg - v.cbegin ())) << " ";
	}
	if (v.size () % 2 != 0)
		cout << *mid;
	if (!v.empty ())
		cout << endl;

	return 0;
}

/*

1 2 3 4 5^Z
3 5 7 9
6 6 3
�밴���������. . .

1 2 3 4 5 6 7 8
^Z
3 5 7 9 11 13 15
9 9 9 9
�밴���������. . .

*/
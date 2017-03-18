/*
* ��ϰ3.20_2������һ���������������Ǵ���һ��vector���󣬽�ÿ�����������ĺ����������
* ��д��ĳ������Ҫ���������1�������1��Ԫ�صĺͣ����������2���͵�����2��Ԫ�صĺͣ��Դ����ơ�
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	vector<int> v;
	int temp;
	while (cin >> temp)
		v.push_back (temp);
	auto size = v.size ();
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	for (vector<int>::size_type i = 0; i < size / 2; i++)
	{
		cout << v[i] + v[size - i - 1] << " ";
	}
	if (size % 2 != 0)		// ������Ԫ��ʱ���������м�Ԫ�ص�ֵ��
	{
		cout << v[size  / 2];
	}
	cout << endl;


	return 0;
}

/*

1 2 3 4 5^Z
1 2 3 4 5
6 6 3
�밴���������. . .

1 2 3 4 5 6^Z
1 2 3 4 5 6
7 7 7
�밴���������. . .

*/
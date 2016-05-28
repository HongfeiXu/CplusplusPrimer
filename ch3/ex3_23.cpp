/*
* ��ϰ3.23����дһ�γ��򣬴���һ������10��������vector����Ȼ��ʹ�õ�����������Ԫ�ص�ֵ����Ϊԭ����������
* �������vector��������ݣ��������Ƿ���ȷ��
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
	for (int i = 0; i < 10; ++i)
		v.push_back (i);
	// ���original v
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	for (auto &i : v)	// ��v�е�ÿ��Ԫ��
		i = 2 * i;
	// �䴦new v
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	
	return 0;
}

/*

0 1 2 3 4 5 6 7 8 9
0 2 4 6 8 10 12 14 16 18
�밴���������. . .

*/
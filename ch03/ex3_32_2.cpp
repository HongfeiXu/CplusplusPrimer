/*
* ��ϰ3.32_2����дһ�γ��򣬶���һ������10��int�����飬��ÿ��Ԫ�ص�ֵ�������±�ֵ��
* �����������鿽��������һ�����顣
* ����vecotr��д����ʵ�����ƵĹ��ܡ�
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	vector<int> iv;
	for (int i = 0; i < 10; i++)
		iv.push_back (i);
	cout << "iv:" << endl;
	for (vector<int>::size_type i = 0; i != 10; i++)
		cout << iv[i] << " ";
	cout << endl;

	vector<int> iv_2;
	for (vector<int>::size_type i = 0; i != 10; i++)
		iv_2.push_back (iv[i]);
	cout << "iv_2" << endl;
	for (vector<int>::size_type i = 0; i != 10; i++)
		cout << iv_2[i] << " ";
	cout << endl;
		
	return 0;
}

/*

iv:
0 1 2 3 4 5 6 7 8 9
iv_2
0 1 2 3 4 5 6 7 8 9
�밴���������. . .

*/
/*
* ��ϰ6.32������ĺ����Ϸ�������Ϸ���˵���书�ܣ�������Ϸ����޸����еĴ��󲢽���ԭ��
*
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int &get (int *array, int index) { return array[index]; };		// �������õĺ���

int main ()
{
	int ia[10];
	for (int i = 0; i != 10; ++i)
	{
		get (ia, i) = i;
	}
	for (auto i : ia)
		cout << i << " ";
	cout << endl;
	return 0;
}

/*

0 1 2 3 4 5 6 7 8 9
�밴���������. . .

*/
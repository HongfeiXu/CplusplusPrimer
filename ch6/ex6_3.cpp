/*
* ��ϰ6.3����д���Լ���fact�������ϻ�����Ƿ���ȷ��
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact (int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}


int main ()
{
	int val = 5;
	cout << fact (val) << endl;

	return 0;
}

/*

120
�밴���������. . .

*/
/*
* ��ϰ4.7������Ǻκ��壿д����������������ı��ʽ��
* ���������������������ܱ�ʾ�ķ�Χʱ�ͻ���������
*/

#include <iostream>
#include <cstring>

using std::cout; 
using std::endl;


int main ()
{
//	cout << sizeof (short) << endl;
	short svalue = 32767;		// ��������short����ռ16λ
	cout << ++svalue << endl;
	unsigned uivalue = 0;
	cout << --uivalue << endl;
	unsigned short usvalue = 65535;
	cout << ++usvalue << endl;

	return 0;
}

/*

-32768
4294967295
0
�밴���������. . .

*/
/*
* ��ϰ5.10����дһ�γ���ʹ��һϵ��if���ͳ�ƴ�cin������ı����ж���Ԫ����ĸ��Ҳͳ�ƴ�д��ʽ��
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main ()
{
	char ch;
	int vowelCnt = 0;
	while (cin >> ch)
	{
		if (ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'A' || ch == 'O' || ch =='E' || ch == 'I' || ch == 'U')
			++vowelCnt;
	}
	cout << vowelCnt << endl;

	return 0;
}

/*

Hello World! What Are You Doing?
^Z
10
�밴���������. . .

*/
/*
* ��ϰ5.9����дһ�γ���ʹ��һϵ��if���ͳ�ƴ�cin������ı����ж���Ԫ����ĸ��
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;


int main ()
{
	char ch;
	int vowelCnt = 0;
	while (cin >> ch)
	{
		if (ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u')
			++vowelCnt;
	}
	cout << vowelCnt << endl;

	return 0;
}

/*

hello world
^Z
3
�밴���������. . .

*/
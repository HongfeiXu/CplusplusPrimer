/*
* P83 ʹ�� range for ���ı��ַ����е��ַ������˴�Ϊ���ַ�����дΪ��д��ĸ����ʽ��
*/

#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main ()
{
	string str ("Hello world!!!");
	for (auto &c : str)
	{
		c = toupper (c);
	}
	cout << str << endl;

	return 0;
}

/*
HELLO WORLD!!!
�밴���������. . .


*/
/*
* ��ϰ3.6����дһ�γ���ʹ�÷�Χfor��佫�ַ����ڵ������ַ���X���档

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
	string str ("Hello World!!!");
	for (auto &c : str)		// �����Ҫ�ı�string�������ַ���ֵ�������ѭ����������Ϊ�������͡�
	{
		c = 'X';
	}
	cout << str << endl;
	
	return 0;
}

/*

XXXXXXXXXXXXXX
�밴���������. . .

*/
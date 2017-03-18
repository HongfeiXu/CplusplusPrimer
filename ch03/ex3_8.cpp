/*
* ��ϰ3.8���ֱ���whileѭ���ʹ�ͳ��forѭ����д��һ��ĳ��������������ʽ�����أ�
* ��ϲ�� range for
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
	cout << str << endl;
	// while
	string::size_type index = 0;
	while (index < str.size ())
		str[index++] = 'X';
	cout << str << endl;
	// for
	for (index = 0; index < str.size (); index++)
		str[index] = 'Y';
	cout << str << endl;
	// range for
	for (auto &c : str)		
		c = 'Z';
	cout << str << endl;
	
	return 0;
}

/*

Hello World!!!
XXXXXXXXXXXXXX
YYYYYYYYYYYYYY
ZZZZZZZZZZZZZZ
�밴���������. . .

*/
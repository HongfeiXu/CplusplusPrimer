/*
* ��ϰ3.10����дһ�γ��򣬶���һ�����������ŵ��ַ�������������ȥ��������ַ���ʣ��Ĳ��֡�
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
	string str ("Hello----------- World!!!");
	for (auto c : str)
	{
		if (!ispunct (c))
			cout << c;
	}
	cout << endl;
	
	return 0;
}

/*

Hello World
�밴���������. . .

*/
/*
* ��ϰ3.3����дһ�γ�����������ַ������Ƚ����Ƿ���Ȳ����������������ȣ�����ϴ���Ǹ��ַ�����
* ��д�������򣬱Ƚ�����������ַ����Ƿ�ǳ���������ȳ���������Ƚϴ���Ǹ��ַ�����
*/

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;


int main ()
{
	string s1, s2;
	cin >> s1 >> s2;
	// �Ƚ����Ƿ���Ȳ����������������ȣ�����ϴ���Ǹ��ַ�����
	if (s1 == s2)
		cout << s1 << "==" << s2 << endl;
	else if (s1 < s2)
		cout << s2 << endl;
	else
		cout << s1 << endl;
	// �Ƚ�����������ַ����Ƿ�ǳ���������ȳ���������Ƚϴ���Ǹ��ַ�����
	if (s1.size () == s2.size ())
		cout << s1 << " 's size equals to " << s2 << endl;
	else if (s1.size () < s2.size ())
		cout << s2 << endl;
	else
		cout << s1 << endl;

	return 0;
}

/*

hello world
world
hello 's size equals to world
�밴���������. . .

*/
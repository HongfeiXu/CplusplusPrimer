/*
* ��ϰ5.19����дһ�γ���ʹ��do whileѭ���ظ���ִ����������������ʾ�û���������string����Ȼ�������϶̵��Ǹ����������
*/

#include <iostream>
#include <string>
#include <cctype>		// tolower()

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main ()
{
	string rsp;
	string s1, s2;
	do
	{
		cout << "Please input two string:" << endl;
		cin >> s1 >> s2;
		if (s1.size () <= s2.size ())
			cout << s1 << " is shorter then " << s2 << endl;
		else
			cout << s2 << " is shorter then " << s1 << endl;
		cout << "More? Enter yes or no: ";
		cin >> rsp;
	} while (tolower (rsp[0]) == 'y');


	return 0;
}

/*

Please input two string:
Hello World
Hello is shorter then World
More? Enter yes or no: Yes
Please input two string:
WOW Hi
Hi is shorter then WOW
More? Enter yes or no: no
�밴���������. . .
*/
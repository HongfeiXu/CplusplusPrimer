/*
* ��ϰ6.17����дһ���������ж� string �������Ƿ��д�д��ĸ����д��һ���������� string ����ȫ���ĳ�Сд��ʽ��
*/

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool any_capital (const string &s)
{
	for (auto c : s)
	{
		if (isupper (c))
			return true;
	}
	return false;
}

void to_lowercase (string &s)
{
	for (auto &c : s)	// ? should I set c a reference, Yes, I should.	P61
		c = tolower (c);
}

int main ()
{
	string s = "Hello World!";
	if (any_capital (s))
		cout << "There are some captials in \"" << s << "\"." << endl;
	else
		cout << "There isn't any captials in \"" << s << "\"." << endl;
	to_lowercase (s);
	cout << s << endl;

	return 0;
}


/*

There are some captials in "Hello World!".
hello world!
�밴���������. . .

*/
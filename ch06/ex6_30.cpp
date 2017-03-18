/*
* ��ϰ6.30�������200ҳ�� str_subrange ������������ı���������δ������еĴ���ġ�
*	1>i:\vs\cplusplus\cplusplus\main.cpp(21): error C2561: ��str_subrange��: �������뷵��ֵ
*
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

bool str_subrange(const string &str1, const string &str2)
{
	if (str1.size () == str2.size ())
		return str1 == str2;
	auto size = (str1.size () < str2.size ())
		? str1.size () : str2.size ();
	for (decltype (size) i = 0; i != size; ++i)
	{
		if (str1[i] != str2[i])
			return;
	}
}

int main ()
{
	string s1 = "Hello";
	string s2 = "What";
	if (str_subrange (s1, s2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

/*

15
40
�밴���������. . .

*/
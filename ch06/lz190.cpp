/*
* ���� p190
* ����һ����Ϊfind_char�ĺ�����������string������ĳ��ָ���ַ���һ�γ��ֵ�λ�á�
* ͬʱ����Ҳϣ�������ܷ��ظ��ַ����ֵ��ܴ�����
*/

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

string::size_type findChar (const string &s, char c, string::size_type &occurs)
{
	string::size_type ret = s.size ();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size (); ++i)
	{
		if (s[i] == c)
		{
			if (ret == s.size ())
				ret = i;
			++occurs;
		}
	}
	return ret;
}

int main ()
{
	string s = "Hello World!";
	string::size_type occurs = 0, firstShow = 0;
	firstShow = findChar (s, 'o', occurs);
	cout << "o occurs " << occurs << " times" << " in string " << s << endl;
	cout << "the first position o show up is index " << firstShow << endl;
	  
	return 0;
}
 

/*

o occurs 2 times in string Hello World!
the first position o show up is index 4
�밴���������. . .

*/
/*
* ��ϰ3.22���޸�֮ǰ�Ǹ����text��һ�εĳ������Ȱ�text�ĵ�һ��ȫ���ĳɴ�д��ʽ��Ȼ�����������
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main ()
{
	vector<string> text;
	// ����ÿһ��
	string line;
	while (getline (cin, line))
		text.push_back (line);
	// �õ������ķ�ʽ����
	for (auto it = text.begin (); it != text.end () && !it->empty(); ++it)		// itΪvector<string>::iterator

	{
		for (auto it2 = it->begin (); it2 != it->end (); ++it2)							// it2Ϊstring::iterator
		{
			*it2 = toupper (*it2);
		}
	// Ҳ�������ַ�ʽ�����ַ�����Ϊ��д��
	//	for (auto &c : *it)
	//		if (islower (c))
	//			c = toupper (c);

		cout << *it << endl;
	}

	return 0;
}

/*

Hello world whate
HI whate areyou

dasj fklas
^Z
HELLO WORLD WHATE
HI WHATE AREYOU
�밴���������. . .

*/
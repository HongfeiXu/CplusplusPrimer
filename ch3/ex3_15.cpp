/*
* ��ϰ3.15����дһ�γ�����cin����һ���ַ����������Ǵ���һ��vector����
*/

#include <iostream>
#include <string>	// ʹ�ñ�׼������string
#include <vector> // ʹ�ñ�׼������vector

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main ()
{
	vector<string> v;
	string temp;
	while (cin >> temp)
	{
		v.push_back (temp);
	}
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}

/*

hello world
^Z
hello world
�밴���������. . .

*/
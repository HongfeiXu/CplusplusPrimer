/*
* ��ϰ3.14����дһ�γ�����cin����һ�������������Ǵ���һ��vector����
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
	vector<int> vint;
	int temp;
	while (cin >> temp)
	{
		vint.push_back (temp);
	}
	for (auto i : vint)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}

/*

1 2 3 4 5
^Z
1 2 3 4 5
�밴���������. . .

*/
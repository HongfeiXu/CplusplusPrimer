/*
* ��ϰ3.25��3.3.3�ڣ���93ҳ�����ַ����εĳ�����ʹ���±������ʵ�ֵģ�
* �����õ�������д�ó���ʵ����ȫ��ͬ�Ĺ��ܡ�
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	vector<unsigned> scores (11, 0);
	for (unsigned grade; cin >> grade; )
	{
		if (grade <= 100)
			++(*(scores.begin () + grade / 10));
	}
	// ���
	for (auto item : scores)
		cout << item << " ";
	cout << endl;
	return 0;
}

/*

42 65 95 100 39 67 95 76 88 76 83 92 76 93
^Z
0 0 0 1 1 0 2 3 2 4 1
�밴���������. . .

*/
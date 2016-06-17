/*
* ��ϰ5.5����дһ�γ���ʹ��if else���ʵ�ְ����ֳɼ�ת������ĸ�ɼ���Ҫ��
*/

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::cout; 
using std::endl;


int main ()
{
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	unsigned grade;
	string lettergrade;
	while (cin >> grade)
	{
		if (grade < 60)
			lettergrade = scores[0];
		else
		{
			lettergrade = scores[(grade - 50) / 10];
			if (grade != 100)
			{
				if (grade % 10 > 7)
					lettergrade += "+";
				else if (grade % 10 < 3)
					lettergrade += "-";
			}
		}
		cout << grade << " " << lettergrade << endl;
	}
	return 0;
}

/*

100
100 A++
90
90 A-
99
99 A+
70
70 C-
77
77 C
54
54 F
^Z
�밴���������. . .

*/
/*
* ��ϰ5.6����д��һ��ĳ���ʹ���������������if else��䡣
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
		//if (grade < 60)
		//	lettergrade = scores[0];
		//else
		//{
		//	lettergrade = scores[(grade - 50) / 10];
		//	if (grade != 100)
		//	{
		//		if (grade % 10 > 7)
		//			lettergrade += "+";
		//		else if (grade % 10 < 3)
		//			lettergrade += "-";
		//	}
		//}
		(grade < 60) ? lettergrade = scores[0]
			: lettergrade = scores[(grade - 50) / 10], grade != 100 ? (grade % 10 > 7 ? lettergrade += "+" : (grade % 10 < 3) ? lettergrade += "-" : lettergrade) : lettergrade;


		cout << grade << " " << lettergrade << endl;
	}
	return 0;
}

/*

100
100 A++
89
89 B+
60
60 D-
47
47 F
^Z
�밴���������. . .

*/
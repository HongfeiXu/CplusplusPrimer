/*
* 练习4.22：将成绩划分成high pass、pass、low pass、fail。
*/

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout; 
using std::endl;


int main ()
{
	vector<unsigned> grades{ 54, 91, 78, 65, 100, 31 };	// 一组待划分的成绩。

	for (auto grade : grades)
	{
		string finalgrade = (grade > 90) ? "high pass"
			: (grade > 75) ? "pass"
			: (grade > 60) ? "low pass"
			: "fail";
		cout << grade << " : "<< finalgrade << endl;
	}
	
	return 0;
}

/*

54 : fail
91 : high pass
78 : pass
65 : low pass
100 : high pass
31 : fail
请按任意键继续. . .

*/
/*
*	练习 9.50：编写程序处理一个 vector<string>，其元素都表示整型值。计算 vector 中所有元素之和。
*	修改程序，使之计算浮点值的 string 之和。
*/


#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> vsInt { "2", "1", "3", "4" };		// list initialize
	vector<string> vsFloat { "1.2", "2.3", "3.4" };

	int sumInt = 0;
	float sumFloat = 0.0f;

	for(auto elem : vsInt)
	{
		sumInt += stoi(elem);
	}

	for(auto elem : vsFloat)
	{
		sumFloat += stof(elem);
	}

	cout << "Sum of int numbers: " << sumInt << endl;
	cout << "Sum of float numers: " << sumFloat << endl;
	
	return 0;
}


/*

Sum of int numbers: 10
Sum of float numers: 6.9
请按任意键继续. . .


*/

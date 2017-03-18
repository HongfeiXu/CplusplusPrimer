/*
*	练习 10.3：用 accumulate 求一个 vector<int> 中的元素之和。
*/

#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> veci{ 1,2,3 };
	vector<double> vecd { 1.2, 2.3, 2.5 };

	auto sum = accumulate(veci.cbegin(), veci.cend(), 0);

	double sum1 = accumulate(vecd.cbegin(), vecd.cend(), 0.0);
	int sum2 = accumulate(vecd.cbegin(), vecd.cend(), 0);		// 5?? 6??  ---- 5 先转换类型，再进行相加

	cout << sum << "\n" << sum1 << "\n" << sum2 << "\n";

	return 0;
}

/*

6
6
5
请按任意键继续. . .

*/
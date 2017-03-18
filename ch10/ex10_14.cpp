/*
*	练习 10.14：编写一个lamdba，接受两个 int，返回它们的和。
*/
#include <iostream>

using namespace std;


int main()
{
	auto lamdba1 = [] (int a, int b) { return a + b; };

	int k = lamdba1(1, 2);
	cout << k << endl;

	return 0;
}

/*

3
请按任意键继续. . .

*/
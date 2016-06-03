/*
* 练习6.5：编写一个函数，输出其实参的绝对值。
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int askuser ()
{
	int val;
	cout << "Please enter a number: ";
	cin >> val;
	return val;
}

void absvalue (int val)
{
	int ans = (val < 0 ? -val : val);
	cout << ans << endl;
}

int main ()
{
	int val = askuser ();
	absvalue (val);

	return 0;
}

/*

Please enter a number: -10
10
请按任意键继续. . .

*/
/*
* 练习6.3：编写你自己的fact函数，上机检查是否正确。
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact (int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}


int main ()
{
	int val = 5;
	cout << fact (val) << endl;

	return 0;
}

/*

120
请按任意键继续. . .

*/
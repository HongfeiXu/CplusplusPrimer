/*
* 练习6.44：将p189的 isShorter 函数改写成内联函数。
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

inline bool isShorter (const string &s1, const string &s2)
{
	return s1.size () < s2.size ();
}

int main ()
{
	cout << isShorter ("Alex", "Roger") << endl;

	return 0;
}

/*

1
请按任意键继续. . .

*/
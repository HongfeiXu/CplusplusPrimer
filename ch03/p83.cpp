/*
* P83 统计字符串中标点的个数。
*/

#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main ()
{
	string str ("Hello world!!!");
	decltype(str.size ()) punct_cnt = 0;
	for (auto c : str)
	{
		if (ispunct (c))
			++punct_cnt;
	}
	cout << punct_cnt << " punction characters in " << str << endl;

	return 0;
}

/*
3 punction characters in Hello world!!!
请按任意键继续. . .


*/
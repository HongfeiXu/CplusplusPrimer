/*
* 练习5.14：编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词。
* 要求记录重复出现的最大次数以及对应的单词。如果这样的单词存在，输出重复出现的最大次数。
* 如果不存在，输出一条信息说明任何单词都没有连续出现过，
*/

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main ()
{
	string repeat;				// 记录到目前为止重复次数最多的字符串
	unsigned repeatCnt = 0;		// 记录重复次数最多的字符串重复的次数
	string now, pre;			// 记录当前输入的字符串，记录前一个输入的字符串，用来确定是否连续。
	unsigned nowCnt = 0;		// 记录当前输入的字符串连续出现的次数，用于同repearCnt比较。

	while (cin >> now)
	{
		if (now == pre)
		{
			++nowCnt;
			if (nowCnt > repeatCnt)
			{
				repeat = now;
				repeatCnt = nowCnt;
			}
		}
		else
		{
			nowCnt = 1;
			pre = now;
		}
	}
	if (repeatCnt > 1)
		cout << repeat << ":\t" << repeatCnt << endl;
	else
		cout << "任何单词都没有连续出现过" << endl;


	return 0;
}

/*

how now now now brown cow cow
^Z
now:    3
请按任意键继续. . .

*/
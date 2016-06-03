/*
* 练习5.20：编写一段程序，从标准输入中读取string对象的序列直到连续出现两个相同的单词或者所有单词都读完为止。
* 使用while循环一次读取一个单词，当一个单词连续出现两次时使用break语句终止循环。输出连续重复出现的单词，或者
* 输出一个消息说明没有任何单词是连续重复的。
* 练习5.21：修改5.20程序，使其找到的重复单词必须以大写字母开头。
*/
#include <iostream>
#include <string>
#include <cctype>		// tolower()

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main ()
{
	string pre, now;
	bool find = false;
	while (cin >> now)
	{
		if (!isupper (now[0]))	// 跳过首字母不是大写的单词
			continue;
		if (now == pre)
		{
			cout << now << endl;
			find = true;
			break;
		}
		else
		{
			pre = now;
		}
	}
	if (!find)
		cout << "没有任何单词是连续重复的。" << endl;


	return 0;
}

/*

Hello world world World World Man Man
World
请按任意键继续. . .

*/
/*
* 练习 8.9：使用你为 8.1.2 节第一个练习所编写的函数打印一个istringstream对象的内容。
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

istream& func(istream& is)
{
	string temp;
	while(is >> temp)		// while 结束后，is 进入错误状态（因为遇到了文件结束标志）
	{
		cout << temp << endl;
	}
	is.clear();				// 对流进行复位，使其处于有效状态。
	return is;
}

int main()
{
	istringstream record(static_cast<string>("Hello world, what are you nongshalei?"));
	istream &is = func(record);		// 我们可以像使用 istream 对象一样来使用 ifstream 和 istringstream 对象。
	cout << is.rdstate() << endl;	// 返回当前流的状态

	return 0;
}

/*

Hello
world,
what
are
you
nongshalei?
0
请按任意键继续. . .

*/
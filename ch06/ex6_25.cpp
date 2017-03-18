/*
* 练习6.25：编写一个main函数，令其接受两个实参。把实参的内容链接成一个string对象并输出出来。
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main (int argc, char *argv[])
{
	string s1 = argv[1];
	string s2 = argv[2];
	cout << s1 + s2 << endl;
	return 0;
}


/*

I:\vs\cplusplus\cplusplus>main Hello World
HelloWorld

I:\vs\cplusplus\cplusplus>

*/
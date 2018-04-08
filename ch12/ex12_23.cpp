/*

练习 12.23：编写一个程序，连接两个字符串字面变量，将结果保存在一个动态分配的 char 数组中。
重写这个程序，连接两个标准库 string 对象。

*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	char *concatenate_string = new char[strlen("hello " "world") + 1]();
	strcat(concatenate_string, "hello ");
	strcat(concatenate_string, "world");
	cout << concatenate_string << endl;
	delete[] concatenate_string;

	string str1("hello "), str2("world");
	cout << str1 + str2 << endl;

	return 0;
}

/*

hello world
hello world
Press any key to continue . . .

*/
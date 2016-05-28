/*
* 练习3.2：编写一段程序从标准输入中一次读入一整行，然后修改改程序使其一次读入一个词。
*/

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;


int main ()
{
	string line;
	// 一次读入一整行
	while (getline (cin, line))
		cout << line << endl;

	// 一次读入一个词
	//while (cin >> line)
	//	cout << line << endl;

	return 0;
}
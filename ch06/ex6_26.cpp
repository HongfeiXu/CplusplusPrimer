/*
* 练习6.26：编写一个程序，使其接受本节所示的选项，输出传递给main函数的实参的内容。
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main (int argc, char *argv[])
{
	cout << argv[1] << " " << argv[2] << " " << argv[3] << " " << argv[4] << argv[5] << endl;
	return 0;
}


/*

I:\vs\cplusplus\cplusplus>main prog -d -o ofile data0
prog -d -o ofiledata0

I:\vs\cplusplus\cplusplus>

*/
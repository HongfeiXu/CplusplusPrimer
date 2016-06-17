/*
* 练习7.11：在你的 Sales_data 类中添加构造函数，然后编写一段程序令其用到每个构造函数。
*/

#include "ex7_11.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main ()
{
	Sales_data item1;
	print (cout, item1) << endl;
	Sales_data item2 (cin);
	print (cout, item2) << endl;
	Sales_data item3 ("2991d");
	print (cout, item3) << endl;
	Sales_data item4 ("2992d", 10, 2.3);
	print (cout, item4) << endl;
}

/*

0 0
2990d 19 0.6
2990d 19 11.4
2991d 0 0
2992d 10 23
请按任意键继续. . .

*/
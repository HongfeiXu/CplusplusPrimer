#include "ex7_41.h"
#include <iostream>
using std::cin;
using std::cout;
int main ()
{
	Sales_data item1;
	print (cout, item1) << endl;
	Sales_data item2 (cin);
	print (cout, item2) << endl;
	Sales_data item3 ("2992d");
	print (cout, item3) << endl;
	Sales_data item4 ("2992e", 10, 2.3);
	print (cout, item4) << endl;
	return 0;
}


/*

非委托构造函数
默认构造函数
0 0
非委托构造函数
默认构造函数
2992c 12 3.9
istream
2992c 12 46.8
非委托构造函数
string
2992d 0 0
非委托构造函数
2992e 10 23
请按任意键继续. . .

*/  
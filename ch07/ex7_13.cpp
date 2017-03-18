/*
* 练习7.13：使用 istream 构造函数重写第229页的程序。
*/

#include <string>
#include "ex7_12.h"
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main ()
{
	Sales_data total(cin);
	if (!total.isbn().empty())
	{
		istream &is = std::cin;
		while (is)
		{
			Sales_data trans (is);
			if (total.isbn () == trans.isbn ())
				total.combine (trans);
			else
			{
				print (cout, total) << endl;
				total = trans;
			}
		}
		print (cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}

/*

I:\vs\cplusplus\cplusplus>main < book_sales
0-201-70353-X 4 99.96
0-201-82470-1 4 181.56
0-201-88954-4 16 198
0-399-82477-1 5 226.95
0-201-78345-X 5 110
0 0

I:\vs\cplusplus\cplusplus>

*/
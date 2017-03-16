/*
练习 13.12：在下面的代码片段（指这里的 fcn 函数）中会发生几次析构函数的调用。
答：3次，accum,item1,item2 各一次。
*/
#include <iostream>
#include "ex7_41.h"

bool fcn(const Sales_data *trans, Sales_data accum)
{
	Sales_data item1(*trans);
	Sales_data item2(accum);
	return item1.isbn() != item2.isbn();
}

int main()
{
	Sales_data *trans = new Sales_data();
	Sales_data sd;

	cout << "enter fcn" << endl;
	fcn(trans, sd);
	cout << "out fcn" << endl;
	
	return 0;
}

/*

enter fcn
destructor
destructor
destructor
out fcn
destructor
Press any key to continue . . .

*/
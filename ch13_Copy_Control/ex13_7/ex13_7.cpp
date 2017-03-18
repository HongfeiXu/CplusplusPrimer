/*

练习 13.7：当我们将一个 StrBlob 赋值给另一个 StrBlob 时，会发生什么？赋值 StrBlobPtr 呢？

将 StrBlob a 赋值给 StrBlob b 时，b 和 a 中的 data 指针指向同一块内存。
将 StrBlobPtr a 赋值给 StrBlobPtr b 时，b 和 a 中的 weakptr wptr 指向同一个对象

*/
#include <iostream>
#include "ex12_19.h"

using std::cout;
using std::endl;

int main()
{
	StrBlob str({ "hello", "world" });
	cout << "before: " << str.count() << endl;
	StrBlob str_cp = str;
	cout << "after: " << str.count() << endl;

	StrBlobPtr p(str);
	cout << "before: " << p.count() << endl;
	StrBlobPtr p_cp = p;
	cout << "after: " << p_cp.count() << endl;

	return 0;
}


/*

before: 1
after: 2
before: 2
after: 2
Press any key to continue . . .

*/
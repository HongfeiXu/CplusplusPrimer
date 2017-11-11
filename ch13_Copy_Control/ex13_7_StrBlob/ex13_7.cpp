/*

��ϰ 13.7�������ǽ�һ�� StrBlob ��ֵ����һ�� StrBlob ʱ���ᷢ��ʲô����ֵ StrBlobPtr �أ�

�� StrBlob a ��ֵ�� StrBlob b ʱ��b �� a �е� data ָ��ָ��ͬһ���ڴ档
�� StrBlobPtr a ��ֵ�� StrBlobPtr b ʱ��b �� a �е� weakptr wptr ָ��ͬһ������

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
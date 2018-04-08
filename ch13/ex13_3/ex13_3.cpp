/*
��ϰ 13.3�������ǿ���һ�� StrBlob ʱ���ᷢ��ʲô������һ�� StrBlobPtr �أ�
*/

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include "ex12_22.h"

using namespace std;

int main()
{
	StrBlob strBlob { string("Hello World"), string("Dark Soull") };
	cout << "before: " << strBlob.count() << endl;
	StrBlob strBlob2 = strBlob;
	cout << "after: " << strBlob.count() << endl;

	ConstStrBlobPtr p(strBlob);
	cout << "before: " << p.count() << endl;
	ConstStrBlobPtr p2 = p;
	cout << "after: " << p.count() << endl;

	return 0;
}

/*

before: 1
after: 2
before: 2
after: 2
Press any key to continue . . .

*/
/*

test

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
	const StrBlob strBlob { string("Hello World"), string("Dark Soull")};

	
	ConstStrBlobPtr pBegin(strBlob.cbegin());
	ConstStrBlobPtr pEnd(strBlob.cend());

	while(pBegin != pEnd)
	{
		cout << pBegin.deref() << endl;
		pBegin.incr();
	}

	
	return 0;
}

/*

Hello World
Dark Soull
Press any key to continue . . .

*/
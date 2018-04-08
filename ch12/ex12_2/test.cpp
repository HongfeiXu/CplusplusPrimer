#include "StrBlob.h"
#include <iostream>

using namespace std;

int main()
{
	StrBlob strblob { "Hello", "World", "Alex" };

	{
		StrBlob strblob2 = strblob;
		strblob2.push_back("Wow");
		cout << strblob2.size() << endl;

	}
	cout << strblob.size() << endl;
	while(!strblob.empty())
	{
		cout << strblob.back() << " ";
		strblob.pop_back();
	}
	cout << endl;

	return 0;
}

/*

4
4
Wow Alex World Hello
Press any key to continue . . .

*/
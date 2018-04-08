#include "ex12_19.h"

int main()
{
	StrBlob strBlob({ "Hello", "World", "This", "is", "IceMJ" });
	strBlob.push_back("Bobo");
	string s("Yes");
	strBlob.push_back(s);
	
	return 0;
}

/*

push_back(&&)
push_back(const &)
请按任意键继续. . .

*/
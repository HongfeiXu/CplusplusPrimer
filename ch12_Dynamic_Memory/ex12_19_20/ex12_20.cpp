/*

练习 12.20：编写程序，逐行读入一个输入文件，将内容存入一个 StrBlob 中，
用一个 StrBlobPtr 打印出 StrBlob 中的每个元素。

在 类StrBlobPtr 中重载了 '!=' 用来控制输出。

*/

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include "ex12_19.h"

using namespace std;

int main()
{
	StrBlob strBlob;
	ifstream inputFile("input.txt");
	
	string line;
	while(getline(inputFile, line))
	{
		strBlob.push_back(line);
	}
	
	StrBlobPtr pBegin(strBlob.begin());
	StrBlobPtr pEnd(strBlob.end());

	while(pBegin != pEnd)
	{
		cout << pBegin.deref() << endl;
		pBegin.incr();
	}

	
	return 0;
}

/*

input.txt:

Hello World!
Keep Moving...
What a Nice day!
Aha!

*/


/*

Hello World!
Keep Moving...
What a Nice day!
Aha!
Press any key to continue . . .

*/
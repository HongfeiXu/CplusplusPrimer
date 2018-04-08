/*

��ϰ 12.20����д�������ж���һ�������ļ��������ݴ���һ�� StrBlob �У�
��һ�� StrBlobPtr ��ӡ�� StrBlob �е�ÿ��Ԫ�ء�

�� ��StrBlobPtr �������� '!=' �������������

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
/*
* 练习5.12：统计以下含有两个字符的字符序列的数量：ff、fl和fi。
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main ()
{
	char ch;
	char prech = '\0';
	unsigned vowelCnt = 0;
	unsigned blankCnt = 0;
	unsigned tabCnt = 0;
	unsigned clCnt = 0;
	unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
	while (cin >> std::noskipws >> ch)		// http://en.cppreference.com/w/cpp/io/manip/skipws
	{								// Enables or disables skipping of leading whitespace by the formatted input functions (enabled by default). Has no effect on output.
		if (ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'A' || ch == 'O' || ch == 'E' || ch == 'I' || ch == 'U')
		{
			++vowelCnt;
			if (prech == 'f' && ch == 'i')
				++fiCnt;
		}
		else if (ch == ' ')
			++blankCnt;
		else if (ch == '\t')
			++tabCnt;
		else if (ch == '\n')
			++clCnt;
		else if (prech == 'f' && ch == 'f')
			++ffCnt;
		else if (prech == 'f' && ch == 'l')
			++flCnt;
		prech = ch;
	}
	cout << "vowel:\t" << vowelCnt << endl;
	cout << "blank:\t" << blankCnt << endl;
	cout << "tab:\t" << tabCnt << endl;
	cout << "cl:\t" << clCnt << endl;
	cout << "ffCnt:\t" << ffCnt << endl;
	cout << "flCnt:\t" << flCnt << endl;
	cout << "fiCnt:\t" << fiCnt << endl;

	return 0;
}

/*

Hello World!
ffuck 3
fi fl wow
^Z
vowel:  6
blank:  4
tab:    0
cl:     3
ffCnt:  1
flCnt:  1
fiCnt:  1
请按任意键继续. . .

*/
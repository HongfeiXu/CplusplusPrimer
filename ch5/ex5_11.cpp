/*
* 练习5.11：修改统计元音字母的程序，使其能够统计空格、制表符和换行符的数量。
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main ()
{
	char ch;
	unsigned vowelCnt = 0;
	unsigned blankCnt = 0;
	unsigned tabCnt = 0;
	unsigned clCnt = 0;
	while (cin >> std::noskipws >> ch)		// http://en.cppreference.com/w/cpp/io/manip/skipws
	{								// Enables or disables skipping of leading whitespace by the formatted input functions (enabled by default). Has no effect on output.
		if (ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'A' || ch == 'O' || ch == 'E' || ch == 'I' || ch == 'U')
			++vowelCnt;
		else if (ch == ' ')
			++blankCnt;
		else if (ch == '\t')
			++tabCnt;
		else if (ch == '\n')
			++clCnt;
	}
	cout << "vowel:\t" << vowelCnt << endl;
	cout << "blank:\t" << blankCnt << endl;
	cout << "tab:\t" << tabCnt << endl;
	cout << "cl:\t" << clCnt << endl;

	return 0;
}

/*

hello World     What Are you
doing?
I am learning!
Just DO IT!
^Z
vowel:  18
blank:  7
tab:    2
cl:     4
请按任意键继续. . .

*/
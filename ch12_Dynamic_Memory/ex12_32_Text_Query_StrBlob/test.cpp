/*
练习 12.32：重写 TextQuery 和 QueryResult 类，用 StrBlob 代替 vector<string> 保存输入文件。
*/

#include "ex12_32.h"
#include <iostream>
#include <fstream>

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	do
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s) || s == "q") 
			break;
		printResult(cout, tq.query(s)) << endl;
	} while(true);
}

int main()
{
	ifstream infile("input.txt");
	runQueries(infile);

	return 0;
}

/*

enter word to look for, or q to quit: Hello
Hello occurs 4 times
(line 1) Hello World!
(line 5) Hello Again
(line 6) Hello Hello
(line 7) And Hello

enter word to look for, or q to quit: World
World occurs 1 time
(line 1) Hello World!

enter word to look for, or q to quit: Again
Again occurs 1 time
(line 5) Hello Again

enter word to look for, or q to quit: Nice
Nice occurs 1 time
(line 3) What a Nice day!

enter word to look for, or q to quit: day
day occurs 1 time
(line 3) What a Nice day!

enter word to look for, or q to quit: q
Press any key to continue . . .


*/
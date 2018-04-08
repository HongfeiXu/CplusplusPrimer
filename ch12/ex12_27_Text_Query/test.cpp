/*
练习 12.27：TextQuery 和 QueryResult 类只使用了我们已经介绍过的语言和标准库特性。
不要提前看后续章节的内容，只用已经学到的只是对这两个类编写你自己的版本。
*/

#include "ex12_27.h"
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

input.txt:

Hello World!
Keep Moving...
What a Nice day!
Aha!
Hello Again
Hello Hello
And Hello


enter word to look for, or q to quit: Hello
Hello occurs 4 times
(1) Hello World!
(5) Hello Again
(6) Hello Hello
(7) And Hello

enter word to look for, or q to quit: And
And occurs 1 time
(7) And Hello

enter word to look for, or q to quit: q
Press any key to continue . . .


*/
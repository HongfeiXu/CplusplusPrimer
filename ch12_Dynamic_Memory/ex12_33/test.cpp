/*
练习 12.33：在  QueryResult 类中添加名为 begin 和 end 的成员，返回一个迭代器，
指向一个给定查询返回的行号的 set 中的位置。在添加一个名为 get_file 的成员，
返回一个 shared_ptr，指向 QueryResult 对象中的文件。
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
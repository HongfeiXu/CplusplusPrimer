/*

练习 17.3：重写 12.3 节的 TextQuery 程序，使用 tuple 代替 QueryResult 类。
你认为那种设计更好？为什么？

我觉得还是用 QueryResult 比较好，因为用 tuple 你很难明白每一个元素代表着什么内容。

*/


#include <tuple>
#include <iostream>
#include <fstream>
#include "ex12_27.h"

using namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	do
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		//printResult(cout, tq.query(s)) << endl;
		printQueryResultTuple(cout, tq.query_v2(s)) << endl;

	} while (true);
}

int main()
{
	ifstream infile("input.txt");
	runQueries(infile);


	return 0;
}

/*

enter word to look for, or q to quit: Now
Now occurs 0 time

enter word to look for, or q to quit: Hello
Hello occurs 4 times
(1) Hello World!
(5) Hello Again
(6) Hello Hello
(7) And Hello

enter word to look for, or q to quit: Again
Again occurs 1 time
(5) Hello Again

enter word to look for, or q to quit: q
请按任意键继续. . .

*/
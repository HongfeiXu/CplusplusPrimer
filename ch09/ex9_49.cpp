/*
*	练习 9.49：读入一个单词文件，输出最长的既不包含上出头部分，也不包含下楚头部分的单词。
*/


#include <string>
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	ifstream in("words.txt");
	string letters("acemnorsuvwxz");
	
	string currentWord, longestWord;
	
	while(in >> currentWord)
	{
		if(currentWord.find_first_not_of(letters) == string::npos && currentWord.size() > longestWord.size())
		{
			longestWord = currentWord;
		}
	}

	in.close();

	if(longestWord.empty())
	{
		cout << "没有满足要求的单词" << endl;
	}
	else
	{
		cout << "最长的复合要求的单词：\n" << longestWord << endl;
	}
	
	return 0;
}


/*

输入文件内容：

a letter has an ascender if, as with d or f, part of the letter extends
above the middle of the line.
a letter has a descender if, as with p or g, part of the letter extends below the line.
write a program that reads a file containing words and reports the longest word
that contains neither ascenders nor descenders.


*/

/*
结果：

最长的复合要求的单词：
nor
请按任意键继续. . .

*/
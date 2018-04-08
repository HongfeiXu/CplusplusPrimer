/*
练习 12.28：编写程序实现文本查询，不要定义类来管理数据。
你的程序应该接受一个文件，并与用户交互来查询单词。
使用 vector 、 map 和 set 容器来保存来自文件的数据并产生查询结果。
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("input.txt");
	
	vector<string> inputLines;
	string temp;
	while(getline(inFile, temp))
	{
		inputLines.push_back(temp);
	}

	map<string, set<int>> dictionary;
	map<string, int> count;  // 记录单词出现的个数

	for(int i = 0; i != inputLines.size(); ++i)
	{
		istringstream lineStream(inputLines[i]);
		string tempWord;
		while(lineStream >> tempWord)
		{
			dictionary[tempWord].insert(i);
			++count[tempWord];  // 递增该单词出现的个数
		}
	}
	while(true)
	{
		cout << "enter word to look for, or q to quit: ";
		string test;
		if(!(cin >> test) || test == "q")
			break;
		else
		{
			cout << test << " occurs " << count[test] << " times" << endl;
			for(auto iterBegin = dictionary[test].cbegin(); iterBegin != dictionary[test].cend(); ++iterBegin)
			{
				cout << "\t(line " << *iterBegin << ")" << inputLines[*iterBegin] << endl;
			}
		}
	}


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

output:

enter word to look for, or q to quit: Hello
Hello occurs 5 times
(line 0)Hello World!
(line 4)Hello Again
(line 5)Hello Hello
(line 6)And Hello
enter word to look for, or q to quit: And
And occurs 1 times
(line 6)And Hello
enter word to look for, or q to quit: Alex
Alex occurs 0 times
enter word to look for, or q to quit: q
Press any key to continue . . .

*/
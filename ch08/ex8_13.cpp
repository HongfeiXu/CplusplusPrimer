/*
* 练习 8.13：重写本节的电话号码程序，从一个命名文件而非 cin 读取数据。
*
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>	
#include <cctype>
#include <fstream>

using namespace std;

bool valid(const string & num);

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main()
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	ifstream ifile("InputPersonInfo.txt");
	ofstream ofile("OutputPersonInfo.txt");

	while(getline(ifile, line))
	{
		PersonInfo info;			// 创建一个保存次记录数据的对象
		record.str(line);			// 将一个 istringstream 与刚刚读取的文本进行绑定， 
									// 从而在此 istringstream 上使用输入运算符来读取当前记录中的每个元素。
		record >> info.name;		// 读取名字
		while(record >> word)		// 读取电话号码
		{
			info.phones.push_back(word);	// 保存电话号码
		}
		people.push_back(info);		// 将此记录追加到people的末尾
									// cout << record.rdstate() << endl;	// 流 record 的当前处于错误状态

		record.clear();		// 将流s的状态复位。从而可以继续使用。
	}

	// 验证每个人的号码，如果该人所有号码都有效，则将这个人的信息写出到文件中
	for(const auto &entry : people)
	{
		ostringstream formatted, badNums;
		for(const auto &nums : entry.phones)
		{
			if(!valid(nums))
			{
				badNums << " " << nums;		// 将数的字符串形式存入 badNums
			}
			else
			{
				formatted << " " << nums;
			}
		}
		if(badNums.str().empty())			// 没有错误的数
			ofile << entry.name << " " << formatted.str() << endl;	// 将有效地号码输入到文件中
		else
			cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;	// 将无效的号码打印出来
	}

	return 0;
}

bool valid(const string & nums)	// 判断号码是否为数字
{
	for(auto c : nums)
	{
		if(!isdigit(c))
		{
			return false;
		}
	}
	return true;
}




/*

InputPersonInfo.txt内容：
Alex  15155901486 12312
Roger 123 18829 9192 1299a9123
Zhu  15156150258 1321
Wu  12311 1891124545 13


终端输出：
input error: Roger invalid number(s)  1299a9123
请按任意键继续. . .

OutputPersonInfo.txt文件内容：
Alex  15155901486 12312
Zhu  15156150258 1321
Wu  12311 1891124545 13


*/
/*
* 练习 8.11：本节的程序在外层 while 循环中定义了 istringstream 对象。如果 record 对象定义在循环之外，你需要对程序进行怎样的修改？
* 重写程序，将 record 的定义移动到 while 循环之外，验证你设想的修改方法是否正确。
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>	

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main()
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;

	while(getline(cin, line))
	{
		PersonInfo info;			// 创建一个保存次记录数据的对象
		record.str(line);	// 将一个 istringstream 与刚刚读取的文本进行绑定， 从而在此 istringstream 上使用输入运算符来读取当前记录中的每个元素。
		record >> info.name;		// 读取名字
		while(record >> word)		// 读取电话号码
		{
			info.phones.push_back(word);	// 保存电话号码
		}
		people.push_back(info);		// 将此记录追加到people的末尾
		// cout << record.rdstate() << endl;	// 流 record 的当前处于错误状态
		record.clear();		// 将流s的状态复位。从而可以继续使用。
	}
	// 输出people的内容
	for(auto &item : people)
	{
		cout << item.name << "  ";
		for(auto &phone : item.phones)
		{
			cout << phone << "  ";
		}
		cout << endl;
	}

	return 0;
}

/*

Morgan 123124 1231231
Alex 123
HongfeiXu 110
^Z
Morgan  123124  1231231
Alex  123
HongfeiXu  110
请按任意键继续. . .
*/
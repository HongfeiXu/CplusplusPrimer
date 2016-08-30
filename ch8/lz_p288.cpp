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

	while(getline(cin, line))
	{
		PersonInfo info;			// 创建一个保存次记录数据的对象
		istringstream record(line);	// 将一个 istringstream 与刚刚读取的文本进行绑定， 从而在此 istringstream 上使用输入运算符来读取当前记录中的每个元素。
		record >> info.name;		// 读取名字
		while(record >> word)		// 读取点画号码
		{
			info.phones.push_back(word);	// 保存电话号码
		}
		people.push_back(info);		// 将此记录追加到people的末尾
	}
	// 输出people的内容
	for(auto item : people)
	{
		cout << item.name << "  ";
		for(auto phone : item.phones)
		{
			cout << phone << "  ";
		}
		cout << endl;
	}

	return 0;
}

/*

morgan 1515590123 1232103401
drew 137192 1273821
^Z
morgan  1515590123  1232103401
drew  137192  1273821
请按任意键继续. . .

*/
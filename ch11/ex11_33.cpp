/*
练习 11.33：实现你自己版本的单词转换程序。

1. 函数 word_transform 管理整个过程
2. 函数 build_map 读取转换规则文件，并创建一个 map，用于保存每个单词到其转换内容的映射
3. 函数 transform 接受一个 string，如果存在转换规则，返回转换后的内容。

*/



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

map<string, string> buildMap(ifstream &map_file);
void word_transform(ifstream &map_file, ifstream &input);
const string & transform(const string &word, map<string, string> &trans_map);

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);	// 保存转换规则
	string text;
	while(getline(input, text))				// 读取一行输入
	{
		istringstream stream(text);			// 构造 istringstream 读取每个单词
		string word;
		bool firstword = true;				// 控制是否打印空格
		while(stream >> word)
		{
			if(firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;
	string key;
	string value;

	while(map_file >> key && getline(map_file, value))
	{
		if(value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	}
	return trans_map;
}

const string & transform(const string &word, map<string, string> &trans_map)
{
	auto map_iterator = trans_map.find(word);
	if(map_iterator != trans_map.cend())
		return map_iterator->second;
		//return trans_map[word];???
	else
		return word;
}

int main()
{
	ifstream map_file("map_file.txt");
	ifstream input("input.txt");

	word_transform(map_file, input);

	return 0;
}


/*

map_file.txt:
brb be right back
k okay?
y why
r are
u you
pic picture
thk thanks
l8r later

input.txt:
where r u
y dont u send me a pic
k thk l8r

*/

/*

where are you
why dont you  send me a picture
okay? thanks later
Press any key to continue . . .

*/
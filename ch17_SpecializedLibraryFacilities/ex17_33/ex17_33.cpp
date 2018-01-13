/*

练习 11.33：实现你自己版本的单词转换程序。

1. 函数 word_transform 管理整个过程
2. 函数 build_map 读取转换规则文件，并创建一个 map，用于保存每个单词到其转换内容的映射
3. 函数 transform 接受一个 string，如果存在转换规则，返回转换后的内容。

练习 17.33：修改 11.3.6 节中的单词转换程序，允许对一个给定的单词有多种转换方式，每次随机选取一种进行实际转换。

*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <random>
#include <ctime>
#include <iterator>
#include <algorithm>

using namespace std;

map<string, vector<string>> buildMap(ifstream &map_file);
void word_transform(ifstream &map_file, ifstream &input);
const string & transform(const string &word, map<string, vector<string>> &trans_map);

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);	// 保存转换规则
	string text;
	while (getline(input, text))				// 读取一行输入
	{
		istringstream stream(text);			// 构造 istringstream 读取每个单词
		string word;
		bool firstword = true;				// 控制是否打印空格
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

map<string, vector<string>> buildMap(ifstream &map_file)
{
	map<string, vector<string>> trans_map;
	string key;
	string values;

	while (map_file >> key && getline(map_file, values))
	{
		if (values.size() > 1)
		{
			// 使用stringstream按空格拆分字符串
			stringstream ss(values);
			string value;
			while (ss >> value)
				trans_map[key].push_back(value);
		}
		else
			throw runtime_error("no rule for " + key);
	}

	return trans_map;
}

const string & transform(const string &word, map<string, vector<string>> &trans_map)
{
	static default_random_engine e(time(nullptr));	// 随机数引擎

	auto map_iterator = trans_map.find(word);
	if (map_iterator != trans_map.cend())
	{
		uniform_int_distribution<int> u(0, map_iterator->second.size() - 1);	// 均匀分布类
		unsigned index = u(e);					// 得到一个随机的整数
		return map_iterator->second[index];
	}
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
k okay Okey OKEY
y why WHY
r are were
u you your
pic picture picnic
thk thanks
l8r later
c see say sea

input.txt:
where r u ?
y dont u send me a pic !
k thk , and c u l8r .

*/

/*

where are your ?
why dont your send me a picture !
Okey thanks , and sea your later .
请按任意键继续. . .

where are you ?
WHY dont your send me a picture !
okay thanks , and sea your later .
请按任意键继续. . .

where are your ?
WHY dont you send me a picnic !
OKEY thanks , and say your later .
请按任意键继续. . .

*/
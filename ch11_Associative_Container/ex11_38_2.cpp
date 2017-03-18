/*

练习 11.38：用 unordered_map 重写单词技术程序和单词转换程序。

Part2 单词转换程序

*/


#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

unordered_map<string, string> buildMap(ifstream &map_file);
const string &transform(const string & word, const unordered_map<string, string> &trans_map);
void word_transform(ifstream &map_file, ifstream &input);

unordered_map<string, string> buildMap(ifstream &map_file)
{
	unordered_map<string, string> trans_map;
	string key;
	string value;
	while(map_file >> key && getline(map_file, value))
	{
		if(value.size() > 1)
		{
			trans_map[key] = value.substr(1);
		}
		else
		{
			throw runtime_error("no ruls for " + key);
		}
	}
	return trans_map;
}

const string &transform(const string & word, const unordered_map<string, string> &trans_map)
{
	auto map_iterator = trans_map.find(word);
	if(map_iterator != trans_map.cend())
	{
		return map_iterator->second;
	}
	else
	{
		return word;
	}
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while(getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while(stream >> word)
		{
			if(firstword)
			{
				firstword = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main()
{
	ifstream map_file("map_file.txt");
	ifstream input("input.txt");
	if(!map_file || !input)
	{
		cerr << "can't find the documents." << endl;
		exit(EXIT_FAILURE);
	}
	word_transform(map_file, input);

	return 0;
}

/*

where are you
why dont you send me a picture
okay? thanks later
Press any key to continue . . .

*/
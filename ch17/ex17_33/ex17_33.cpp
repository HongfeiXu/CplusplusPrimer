/*

��ϰ 11.33��ʵ�����Լ��汾�ĵ���ת������

1. ���� word_transform ������������
2. ���� build_map ��ȡת�������ļ���������һ�� map�����ڱ���ÿ�����ʵ���ת�����ݵ�ӳ��
3. ���� transform ����һ�� string���������ת�����򣬷���ת��������ݡ�

��ϰ 17.33���޸� 11.3.6 ���еĵ���ת�����������һ�������ĵ����ж���ת����ʽ��ÿ�����ѡȡһ�ֽ���ʵ��ת����

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
	auto trans_map = buildMap(map_file);	// ����ת������
	string text;
	while (getline(input, text))				// ��ȡһ������
	{
		istringstream stream(text);			// ���� istringstream ��ȡÿ������
		string word;
		bool firstword = true;				// �����Ƿ��ӡ�ո�
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
			// ʹ��stringstream���ո����ַ���
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
	static default_random_engine e(time(nullptr));	// ���������

	auto map_iterator = trans_map.find(word);
	if (map_iterator != trans_map.cend())
	{
		uniform_int_distribution<int> u(0, map_iterator->second.size() - 1);	// ���ȷֲ���
		unsigned index = u(e);					// �õ�һ�����������
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
�밴���������. . .

where are you ?
WHY dont your send me a picture !
okay thanks , and sea your later .
�밴���������. . .

where are your ?
WHY dont you send me a picnic !
OKEY thanks , and say your later .
�밴���������. . .

*/
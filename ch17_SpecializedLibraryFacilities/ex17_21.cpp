/*

练习 17.21: 使用本节中定义的 valid 函数重写 8.3.2 节中的电话号码程序。

*/

#include <regex>
#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>

using namespace std;


struct PersonInfo {
	string name;
	vector<string> phones;
};

void inputPersonInfo(vector<PersonInfo>& people, istream& is);
void outputPersonInfo(const vector<PersonInfo>& people, ostream& os);
bool valid(const smatch& m);
string format(string phone);

int main()
{
	vector<PersonInfo> people;
	inputPersonInfo(people, cin);
	outputPersonInfo(people, cout);
	
	return 0;
}

void inputPersonInfo(vector<PersonInfo>& people, istream& is)
{
	string line, phone;
	while (getline(is, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> phone)
			info.phones.push_back(phone);
		people.push_back(info);
	}
}

void outputPersonInfo(const vector<PersonInfo>& people, ostream& os)
{
	string pattern =
		"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(pattern);

	for (const auto & entry : people)
	{
		ostringstream formatted, badNums;
		for (const auto & phone : entry.phones)
		{
			for (sregex_iterator it(phone.begin(), phone.end(), r), it_end; it != it_end; ++it)
			{
				if (!valid(*it))
					badNums << " " << phone;
				else
					formatted << " " << format(phone);
			}
		}

		if (badNums.str().empty())
			os << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
	}
}

bool valid(const smatch& m)
{
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

string format(string phone)
{
	return phone;
}

/*

Alex 131-221-1231
James 131-121.1122
^Z
Alex  131-221-1231
input error: James invalid number(s)  131-121.1122
请按任意键继续. . .

*/

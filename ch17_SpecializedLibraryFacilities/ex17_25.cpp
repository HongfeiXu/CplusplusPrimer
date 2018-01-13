/*

练习 17.25：重写你的电话号码程序，使之只输出每个人的第一个电话号码。

*/

#include <regex>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	vector<string> input;
	input.push_back("morgan (201) 555-2368 862-555-0123");
	input.push_back("drew (973)555.0130");
	input.push_back("lee (609) 555-0132 2015550175 800.555.0000");

	string pattern("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})");
	regex r;
	try
	{
		r = pattern;
	}
	catch (regex_error e)
	{
		cout << e.what() << " : " << e.code() << endl;
	}
	
	string fmt = "$2-$5-$7";

	for (const auto& item : input)
	{
		smatch result;
		regex_search(item, result, r);
		if (!result.empty())
		{
			cout << result.prefix() << result.format(fmt) << endl;
		}
		else
		{
			cout << "sorry, no match." << endl;
		}
	}

	return 0;
}
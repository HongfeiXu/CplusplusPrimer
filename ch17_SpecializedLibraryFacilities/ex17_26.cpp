/*

练习 17.26：重写你的电话号码程序，使之对于多于一个电话号码的人只输出第二个和后续电话号码

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
			smatch next_result;
			string suffix = result.suffix().str();
			regex_search(suffix, next_result, r);	// 在进行一次搜索匹配
			if (next_result.empty())				// 若匹配失败，则说明只有一个电话号码，输出
			{
				cout << result.prefix() << result.format(fmt) << endl;
			}
			else									// 若匹配成功，则说明有多个电话号码，输出姓名，然后对 suffix 进行 regex_replace 输出后面的号码
			{
				cout << result.prefix();
				cout << regex_replace(suffix, r, fmt) << endl;
			}
		}
		else
		{
			cout << "Sorry, No match." << endl;
		}
	}

	return 0;
}
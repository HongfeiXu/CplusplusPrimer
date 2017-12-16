/*

练习 17.1：定义一个保存三个 int 值得 tuple，并将其成员分别初始化为 10、20 和 30
练习 17.2：定义一个 tuple，保存一个 string、一个 vector<string> 和一个 pair<string, int>

*/


#include <tuple>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>

using namespace std;

int main()
{
	tuple<int, int, int> threeInt(10, 20, 30);

	tuple<string, vector<string>, pair<string, int>> tu(string("Hello"), { "world", "war" }, { "Ice", 3 });

	return 0;
}
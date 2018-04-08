/*

	练习 11.9：定义一个 map，将单词与一个行号的 list 关联，list 中保存的是单词所出现的行号。
	练习 11.10：可以定义一个 vector<int>::iterator 到 int 的 map 吗？
	list<int>::iterator 到 int 的 map 呢？

*/

#include <list>
#include <vector>
#include <string>
#include <map>

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// ex 11.9
	map<string, list<std::size_t>> m;

	// ex10 can be declared
	map<vector<int>::iterator, int> mV;
	map<list<int>::iterator, int> mL;

	vector<int> vi { 1,2,3 };
	mV.insert(pair<vector<int>::iterator, int> (vi.begin(), 1));

	list<int> li { 1,2,3 };
	//  error C2678: binary '<': no operator found which takes a left-hand operand of type 'const std::_List_iterator<std::_List_val<std::_List_simple_types<int>>>' (or there is no acceptable conversion)
	// 因为 list 的迭代器默认不支持运算 > >= < <=
	mL.insert(pair<list<int>::iterator, int> (li.begin(), 1));

	return 0;
}

/*

Hello World World Wow Hello Bobo
^Z
Hello World Wow Bobo
请按任意键继续. . .

*/
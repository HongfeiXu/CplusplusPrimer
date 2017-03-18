/*
* 练习 9.14：编写程序，将一个 list 中的 char* 指针（指向C风格字符串）元素赋值给一个 vector 中的 string.
*/
#include <string>
#include <list>
#include <vector>

#include <iostream>

using std::string;
using std::list;
using std::vector;

using std::cout;
using std::endl;


int main()
{
	list<const char *> lc = { "Hello", "World", "!" };
	vector<string> vs;
	vs.assign(lc.cbegin(), lc.cend());
	for(auto item : vs)
		cout << item << " ";
	cout << endl;

	return 0;
}


/*

Hello World !
请按任意键继续. . .

*/
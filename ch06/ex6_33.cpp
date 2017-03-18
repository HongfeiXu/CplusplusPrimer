/*
* 练习6.33：编写一个递归函数，输出 vector 对象的内容。
* 此处，通过迭代器来实现。
*/

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void printVector (vector<string>::iterator sbeg, vector<string>::iterator send)
{
	if (sbeg == send)
	{
		cout << endl;
		return;
	}
		cout << *sbeg << " ";
	sbeg += 1;
	printVector (sbeg, send);
}

int main ()
{
	vector<string> sv = { "hello", "world", "wow", "hey" };
	printVector (sv.begin (), sv.end ());
	return 0;
}

/*

hello world wow hey
请按任意键继续. . .

*/
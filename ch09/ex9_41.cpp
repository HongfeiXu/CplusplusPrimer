/*
* 练习 9.41：编写程序，从一个 vector<char> 初始化一个 string。
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<char> vc;
	vc = { 'h', 'e', 'l', 'l', 'o' };

	string s(vc.cbegin(), vc.cend());
	
	cout << s << endl;

	return 0;
}

/*

hello
请按任意键继续. . .

*/
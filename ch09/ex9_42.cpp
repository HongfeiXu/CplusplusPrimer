/*
* 练习 9.42：假定你希望每次读取一个字符存入一个 string 中，而且知道最少需要读取 100 个字符，应该如何提高程序的性能。
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	s.reserve(120);			// use reserve to allocate enough space for the string. 这样就避免了多次申请内存的操作。

	char c;
	while(cin >> c)
	{
		s.push_back(c);
		cout << s.capacity() << endl;
	}

	return 0;
}

/*


*/
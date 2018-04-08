/*
练习13.5：给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。
你的构造函数应该动态分配一个新的 string，并将对象拷贝到 ps 指向的位置，而不是拷贝 ps 本身。
*/

#include <string>
#include <iostream>
#include <memory>
using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) { cout << "Call Constructor" << endl; }
	HasPtr(const HasPtr &orig) : ps(new string(*(orig.ps))), i(orig.i) { cout << "Call Copy Constructor" << endl; }
	const string &GetString()
	{
		return *ps;
	}
private:
	shared_ptr<string> ps;
	int i;
};

// test
int main()
{
	HasPtr hp("Hello");
	HasPtr hp2(hp);
	HasPtr hp3("wow");
	cout << hp.GetString() << endl;
	cout << hp2.GetString() << endl;
	cout << hp3.GetString() << endl;

	hp = hp3;  // 由于每个对象有自己的内存，用ps指针进行管理，所以，当更改 hp 时， hp2 不会改变

	cout << hp.GetString() << endl;
	cout << hp2.GetString() << endl;
	cout << hp3.GetString() << endl;

	return 0;
}

/*

Call Constructor
Call Copy Constructor
Call Constructor
Hello
Hello
wow
wow
Hello
wow
Press any key to continue . . .

*/
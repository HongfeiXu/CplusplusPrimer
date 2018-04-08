/*

练习 12.6：编写函数，返回一个动态分配的 int 的 vector。将此 vector 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中。
再将 vector 传递给另一个函数，打印读入的值。记得在恰当的时刻 delect vector。

练习 12.7：重做上一题，这次使用 shared_ptr 而不是内置指针。

*/

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

shared_ptr<vector<int>> foo()
{
	shared_ptr<vector<int>> p = make_shared<vector<int>>();
	p->push_back(1);
	p->push_back(2);
	p->push_back(3);
	p->push_back(4);
	p->push_back(5);
	return p;
}

void foo1(istream &input, shared_ptr<vector<int>> p)
{
	int temp;
	while(input >> temp)
	{
		p->push_back(temp);
	}
}

void foo2(shared_ptr<vector<int>> p)
{
	for(auto elem : *p)
	{
		cout << elem << " ";
	}
	cout << endl;
}

int main()
{
	auto p = foo();
	foo1(cin, p);
	foo2(p);

	return 0;
}

/*

6 7 8 9 10
^Z
1 2 3 4 5 6 7 8 9 10
Press any key to continue . . .

*/
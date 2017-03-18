/*

练习 12.6：编写函数，返回一个动态分配的 int 的 vector。将此 vector 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中。
再将 vector 传递给另一个函数，打印读入的值。记得在恰当的时刻 delect vector。

*/

#include <vector>
#include <iostream>

using namespace std;



// foo() 返回一个动态分配的 int 的 vector。
vector<int> * foo()
{
	auto p = new vector<int> { 1,2,3,4,5 };
	return p;
}

// foo1() 读取标准输入，将读入的值保存在 vector 元素中。
void foo1(istream &input, vector<int> * vip)
{
	int n;
	while(input >> n)
	{
		vip->push_back(n);
	}
}

// foo2() 打印输入的值
void foo2(vector<int> *vip)
{
	for(auto elem : *vip)
	{
		cout << elem << " ";
	}
	cout << endl;
}

int main()
{
	auto vip = foo();
	foo1(cin, vip);
	foo2(vip);
	
	delete vip;
	
	return 0;
}

/*

6 7 8 9 10
^Z
1 2 3 4 5 6 7 8 9 10
Press any key to continue . . .

*/
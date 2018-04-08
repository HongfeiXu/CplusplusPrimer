/*
练习 13.13：给 X 添加拷贝赋值运算符和析构函数，并编写一个程序以不同港式使用 X 的对象：将它们作为非引用和引用参数传递；
动态分配它们；
*/
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct X
{
	X() : data(0) 
	{ 
		cout << "X()" << endl; 
	}

	X(const X& rhs) : data(rhs.data) 
	{ 
		cout << "X(const X&)" << endl; 
	}

	X& operator=(const X &rhs) 
	{ 
		data = rhs.data; 
		cout << "operator=(const X&)" << endl;
		return *this;
	}

	~X() 
	{ 
		cout << "~X()" << endl; 
	}
	
	int data;
};

void PrintXData(X x)
{
	cout << "PrintXData(X) " << x.data << endl;
}

void PrintXData2(X &x)
{
	cout << "PrintXData2" << x.data << endl;
}

int main()
{
#if 0
	X x;
	PrintXData(x);
	PrintXData2(x);
	cout << endl;
#endif

	vector<X> vx(2);
	X x1, x2;
	vx.push_back(x1);
	vx.push_back(x2);
	cout << vx.capacity() << endl;

	return 0;
}


/*

X()
X()
X()
X()
X(const X&)
X(const X&)
~X()
~X()
X(const X&)
X(const X&)
X(const X&)
X(const X&)
~X()
~X()
~X()
X(const X&)
4
~X()
~X()
~X()
~X()
~X()
~X()
Press any key to continue . . .

*/
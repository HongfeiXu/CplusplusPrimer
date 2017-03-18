/*
练习13.4：假定 Point 是一个类类型，它有一个 public 的拷贝构造函数，
指出下面程序片段中哪些地方使用了拷贝构造函数。
特殊的是 *heap = new Point(global); 调用的是拷贝构造函数。
*/
#include <iostream>

using namespace std;

class Point
{
public:
	Point() { cout << "Call Constructor 1" << endl; }
	Point(float x_, float y_) : x(x_), y(y_) { cout << "Call Constructor 2" << endl; }
	Point(const Point& orig) : x(orig.x), y(orig.y)
	{
		cout << "Call Copy Constructor" << endl;
	}

private:
	float x = 0;
	float y = 0;
};

Point global;  // Call Constructor 1

Point foo_bar(Point arg)
{
	Point local = arg, *heap = new Point(global);  // Call Copy Constructor  Call Copy Constructor
	*heap = local;
	Point pa[4] = { local, *heap };  // Call Copy Constructor  Call Copy Constructor  Call Constructor 1  Call Constructor 1
	return *heap;  // Call Copy Constructor
}

int main()
{
	Point p(1, 2); // Call Constructor 2
	foo_bar(p);  // Call Copy Constructor
	
	return 0;
}

/*

Call Constructor 1
Call Constructor 2
Call Copy Constructor
Call Copy Constructor
Call Copy Constructor
Call Copy Constructor
Call Copy Constructor
Call Constructor 1
Call Constructor 1
Call Copy Constructor
Press any key to continue . . .

*/
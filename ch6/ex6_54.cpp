/*
* 练习6.54：编写函数的声明，令其接受两个 int 形参并且返回类型也是 int；
* 然后声明一个 vector 对象，令其元素时指向该函数的指针。
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int func (int a, int b)
{
	return a + b;
}

using pf1 = int (*) (int, int);
typedef int (*pf2) (int, int);
using pf3 = decltype(func) *;

int main ()
{
	vector<pf2> vf;
	vf.push_back (func);

	return 0;
}
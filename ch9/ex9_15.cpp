/*
* 练习 9.15：编写程序，判定两个 vector<int> 是否相等。
* 练习 9.16：重写上一题的程序，比较一个 list<int> 中的元素和一个 vector<int> 的元素
*/
#include <vector>
#include <list>

#include <iostream>

using std::vector;
using std::list;

using std::cout;
using std::endl;

void judge(const vector<int> &v1, const vector<int> &v2);

int main()
{
	vector<int> v1 = { 1, 2, 3, 4 };
	list<int> l1 = { 1, 2, 3 };				// 因为关系运算符左右两边的运算对象必须是相同的容器类型，所以需要转换。

//	vector<int> v2(l1.cbegin(), l1.cend());	// 先将 l1 的元素拷贝到另一个 vector 中，然后通过比较运算符比较这两个 vector
//	judge(v1, v2);	
	judge(v1, vector<int>(l1.cbegin(), l1.cend()));	// 效果等同于上面两句，创建了一个临时 vector<int> 对象作为参数传递给 judge 函数
	

	return 0;
}

void judge(const vector<int> &v1, const vector<int> &v2)
{
	if(v1 < v2)
		cout << "a < b" << endl;
	else if(v1 > v2)
		cout << "a > b" << endl;
	else
		cout << "a == b" << endl;
}


/*

a > b
请按任意键继续. . .

*/
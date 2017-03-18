/*
* 练习 9.11：对6种创建和初始化 vector 对象的方法，每一种都给出一个实例。解释每个 vector 包含什么值。
*/
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void printVector(const vector<int> &v);


int main()
{
	vector<int> v1;				// v1 为空
	printVector(v1);

	vector<int> v2 { 2, 3, 4 };	// v2 有3个元素 2,3,4
	// vector<int> v2 = {2, 3, 4};
	printVector(v2);

	vector<int> v3(v2);			// v3 初始化为 v2 的拷贝，有3个元素 2,3,4
	// vector<int> v3 = v2;	
	printVector(v3);
		
	vector<int> v4(v2.cbegin(), v2.cbegin() + 2);	// v4 初始化为迭代器 v2.cbegin() 和 v2.cbegin() + 2 范围中的元素的拷贝，有2个元素 2,3
	printVector(v4);

	vector<int> v5(5);			// v5 包含 5 个元素，这些元素进行了值初始化，初始值为 0
	printVector(v5);

	vector<int> v6(6, 1);		// v6 包含 6 个元素，这些元素初始化为 1
	printVector(v6);
	

	return 0;
}

void printVector(const vector<int> &v)
{
	cout << "Vector: ";
	for(auto item : v)
	{
		cout << item << " ";
	}
	cout << endl;
}

/*

Vector:
Vector: 2 3 4
Vector: 2 3 4
Vector: 2 3
Vector: 0 0 0 0 0
Vector: 1 1 1 1 1 1
请按任意键继续. . .

*/
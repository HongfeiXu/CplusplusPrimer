/*
*	练习 10.28：一个 vector 中保存 1 到 9，将其拷贝到三个其他容器中。分别使用 inserter、back_inserter
*	和 front_inserter 将元素添加到三个容器中。运行程序验证你的估计是否正确。
*/

#include <vector>
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vi { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	vector<int> vi2, vi3;
	list<int> li4;			// vector 不支持 push_front，故不能使用 front_inserter()

	copy(vi.cbegin(), vi.cend(), inserter(vi2, vi2.end()));		// 123456789
	copy(vi.cbegin(), vi.cend(), back_inserter(vi3));			// 123456789
	copy(vi.cbegin(), vi.cend(), front_inserter(li4));			// 987654321

	cout << "vi2: ";
	for_each(vi2.cbegin(), vi2.cend(), [](const int &i){cout << i << " "; });
	cout << endl;

	cout << "vi3: ";
	for_each(vi3.cbegin(), vi3.cend(), [](const int &i){cout << i << " "; });
	cout << endl;
	
	cout << "li4: ";
	for_each(li4.cbegin(), li4.cend(), [](const int &i){cout << i << " "; });
	cout << endl;

	return 0;
}

/*

vi2: 1 2 3 4 5 6 7 8 9
vi3: 1 2 3 4 5 6 7 8 9
li4: 9 8 7 6 5 4 3 2 1
请按任意键继续. . .

*/
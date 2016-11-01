/*
* 练习 10.5：在本节对名册(roster)调用 equal 的例子中，如果两个名册中保存的都是 C 风格字符串而不是 string，会发生什么？
*/

#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<const char *> vc { "hello", "world" };
	vector<const char *> vc2 { "hello", "world" , "WoW"};

	cout << boolalpha << equal(vc.cbegin(), vc.cend(), vc2.cbegin()) << "\n";


	cout << (void*) vc.front() <<" "<< (void*) vc[1] << endl;
	cout << (void*) vc2.front() <<" " << (void*) vc2[1] << endl;


	// 验证
	const char a[3][3] = { "Aa", "Bb", "Cc" };
	const char b[3][3] = { "Aa", "Bb", "Cc" };

	vector<const char*> v1(begin(a), end(a));
	vector<const char*> v2(begin(b), end(b));

	cout << boolalpha << equal(v1.cbegin(), v1.cend(), v2.cbegin()) << "\n";
	cout << (void *) v1.front() << endl;
	cout << (void *) v2.front() << endl;

	return 0;
}

/*


Equal!
00DBF22C 00DBF234
00DBF22C 00DBF234
请按任意键继续. . .


得到结果乍看同 vector<string> 时相同。
但事实上，这只是表象的相同。
思考下： vc 中的 "hello"，"world" 和 vc2 中的 "hello"，"world"，"WoW" 都是字面值， 编译器会优化他们，尽量不去重复存储它们，因此相同的字面值很可能会具有相同的地址，
这在最后两行输出中体现了出来。

为了让不同容器中的相同字符串处在不同的地址下，我们先将字符串存储在数组中。


true
0124022C 01240234
0124022C 01240234
false
010FFE60
010FFE4C
请按任意键继续. . .

v1 和 v2 中存储了指向相同值得指针（但地址不同），最后 equal 的返回值是 false。由此可见 equal 比较的并不是正真的字符串，而是它们的地址。


注意：如果我们将 v1 v2 定义为 指针数组，则 equal 的返回值又是 true。

So literals of same contents pointed to by pointers share the same memories, but literals in arrays are stored individually.

*/
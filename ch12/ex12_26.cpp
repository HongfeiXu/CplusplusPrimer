/*

练习 12.26：用 allocator 重写第 427 页中的程序。

*/

#include <memory>
#include <string>
#include <iostream>

using namespace std;

int main()
{
#if 0
	const size_t max = 10;
	string *const p = new string[max];
	string *q = p;
	string s;
	while(cin >> s && q != p + max)
	{
		*q++ = s;
	}
	const size_t size = q - p;  // 记住我们读取了多少个 string

	// 使用数组
	delete[] p;
#endif

	const size_t max = 3;
	allocator<string> alloc;
	auto const p = alloc.allocate(max);  // 分配一段原始内存
	auto q = p;  // q 指向最后构造的元素之后的位置
	string s;
	while(cin >> s && q != p + max)
	{
		alloc.construct(q++, s);  // 在分配的原始内存中构造对象
	}
	const size_t size = q - p;  // 记录实际构造了的元素数目
	for(int i = 0; i != size; ++i)
	{
		cout << *(p + i) << endl;
	}
	while(q != p)
	{
		alloc.destroy(--q);  // 销毁构造的元素，从而内存再次变为原始、未构造的内存。
	}
	alloc.deallocate(p, max);  // 释放被分配的内存

	return 0;
}

/*

Hello World
^Z
Hello
World
Press any key to continue . . .


Hello Hello Hello Hello
Hello
Hello
Hello
Press any key to continue . . .

*/
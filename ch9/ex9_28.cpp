/*
* 练习 9.28：编写函数，接受一个 forward_list<string> 和两个 string 工三个参数。
* 函数应在链表中查找第一个 string，并将第二个 string 插入到紧接着第一个 string 之后的位置。
* 若第一个 string 未在链表中，则将第二个 string 插入到链表末尾。
*/

#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void search_and_insert(forward_list<string> &flst, string s1, string s2);

int main()
{
	forward_list<string> flst = { "Hello", "!", "What", "Hello", "Alex" };
	
	search_and_insert(flst, "Hello", "Hello");			// 在 Hello 后面 插入 Hello

	for(auto item : flst)
	{
		cout << item << " ";
	}
	cout << endl;

	flst.assign({ "Hello", "!", "What", "Hello", "Alex" });	// 将 flst 重新复制为原来的内容
	search_and_insert(flst, "Hello", "World");

	for(auto item : flst)
	{
		cout << item << " ";
	}
	cout << endl;

	flst.assign({ "Hello", "!", "What", "Hello", "Alex" });	// 将 flst 重新复制为原来的内容
	search_and_insert(flst, "Roger", "World");

	for(auto item : flst)
	{
		cout << item << " ";
	}
	cout << endl;

	return 0;
}

void search_and_insert(forward_list<string> &flst, string s1, string s2)
{
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	
	bool findString = false;

	for(; curr != flst.end(); ++curr, ++ prev)
	{
		if(*curr == s1)
		{
			findString = true;
			curr = flst.insert_after(curr, s2);		// curr 指向当前插入的元素（这样可以防止 s1 == s2 时出现的死循环），新插入的 s2 不在和 s1 比较。

		}
	}
	if(!findString)
	{
		flst.insert_after(prev, s2);
	}
}


/*

Hello Hello ! What Hello Hello Alex
Hello World ! What Hello World Alex
Hello ! What Hello Alex World
请按任意键继续. . .

*/
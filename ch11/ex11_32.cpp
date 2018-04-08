/*

练习 11.31：编写程序，定义一个作者及其作品的 multimap。
使用 find 在 multimap 中查找一个元素并用 erase 删除它。
确保你的程序在元素不在 map 中时也能正常运行。

练习 11.32：使用上一题定义的 multimap 编写程序，按字典序打印作者列表和他们的作品。
注：如果不加处理， multimap 中作者列表按序，但作品却不保证有序。因此需要在进行处理。

*/

#include <map>
#include <set>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	multimap<string, string> authors;
	authors.insert({ "Hongfei", "CG" });
	authors.insert({ "Alex", "GameDev" });
	authors.insert({ "Hongfei", "C++" });
	authors.insert({ "Alex", "Unity3D" });
	authors.insert({ "Alex", "Python" });

	cout << "before process:\n";
	for(const auto &elem : authors)
	{
		cout << elem.first << " : " << elem.second << endl;
	}

	cout << "after process:\n";
	// 将一个作者的著作存在 multiset 中，这样一个作者对应 map 中的一项，且书是按序顺序保存
	map<string, multiset<string>> ordered_authors;		

	for(const auto &elem : authors)
	{
		ordered_authors[elem.first].insert(elem.second);
	}
	
	for(const auto &elem : ordered_authors)
	{
		cout << elem.first << ": ";
		for(const auto &book : elem.second)
			cout << book << " ";
		cout << endl;
	}


	return 0;
}


/*

Before Find And Erase:
Alex : GameDev
Alex : Unity3D
Hongfei : CG
Hongfei : C++

After Find And Erase:
Alex : Unity3D
Hongfei : CG
Hongfei : C++
请按任意键继续. . .


*/
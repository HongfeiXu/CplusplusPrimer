/*

练习 11.31：编写程序，定义一个作者及其作品的 multimap。
使用 find 在 multimap 中查找一个元素并用 erase 删除它。
确保你的程序在元素不在 map 中时也能正常运行。

*/

#include <map>
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
	
	cout << "Before Find And Erase:" << endl;
	for(const auto &elem : authors)
	{
		cout << elem.first << " : " << elem.second << endl;
	}

	auto iter = authors.find("Alex");
	if(iter != authors.end())
	{
		authors.erase(iter);
	}
	else
	{
		cout << "Not found!"<< endl;
	}

	cout << endl;

	cout << "After Find And Erase:" << endl;
	for(const auto &elem : authors)
	{
		cout << elem.first << " : " << elem.second << endl;
	}

	// 删除所有以 Alex 为 key 的元素。
	//auto pos = authors.equal_range("Alex");
	//authors.erase(pos.first, pos.second);

	//cout << "After Find And Erase:" << endl;
	//for(auto elem : authors)
	//{
	//	cout << elem.first << " : " << elem.second << endl;
	//}



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
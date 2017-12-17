/*
练习 17.4：编写并测试你自己版本的 findBook 函数
练习 17.5：重写 findBook，令其返回一个 pair，包含一个索引和一个迭代器 pair
练习 17.6：重写 findBook，不使用 tuple 或 pair
练习 17.7：解释你更倾向于那个版本的 findBook，为什么？

更倾向于 tuple 版本的，更灵活，程序也比较容易理解。
struct 版本的最容易理解，但编写起来比较啰嗦。

练习 17.8：在本节最后一段代码中，如果我们将 Sales_data() 作为第三个参数传递给 accumulate，会发生什么？
如果将 Sales_data() 作为第三个参数，则调用 Sales_data 的默认构造函数，构造出的 Sales_data 对象

bookNo = string("")
units_sold = 0;
revenue = 0.0;

不影响 accumulate 的正常计算，所以是可以的。

*/

#include "Sales_data.h"
#include <tuple>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

// 使用 tuple 返回多个值

// vector<vector<Sales_data>> files;
// 编写函数，对于一本给定的书，在 files 中搜索出售过这本书的书店。
// 对每家有匹配销售记录的书店，我们创建一个 tuple 来保存这家书店的索引和两个迭代器。

// matches 有三个成员，一家书店的索引，和两个指向书店 vector 中元素的迭代器
typedef tuple<vector<vector<Sales_data>>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;


vector<matches>
findBook(const vector<vector<Sales_data>>& files,
		 const string& book)
{
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
		{
			ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
		}
	}

	return ret;
}

void reportResult(istream& in, ostream& os, const vector<vector<Sales_data>>& files)
{
	string book;
	while (in >> book)
	{
		auto trans = findBook(files, book);		// 销售了这本书的书店
		if (trans.empty())
		{
			cout << book << " not found in any store" << endl;
			continue;
		}
		for (const auto& store : trans)			// 对每家销售了给定书籍的书店
		{
			os << "store " << get<0>(store) << " sales: "
				<< accumulate(get<1>(store), get<2>(store), Sales_data(book))
				<< endl;
		}
	}
}

/*

练习 17.5：重写 findBook，令其返回一个 pair，包含一个索引和一个迭代器 pair

*/

typedef pair<vector<vector<Sales_data>>::size_type, pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> matches_v2;

vector<matches_v2>
findBook_v2(const vector<vector<Sales_data>>& files,
		 const string& book)
{
	vector<matches_v2> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
		{
			ret.push_back(make_pair(it - files.cbegin(), make_pair(found.first, found.second)));
		}
	}

	return ret;
}

void reportResult_v2(istream& in, ostream& os, const vector<vector<Sales_data>>& files)
{
	string book;
	while (in >> book)
	{
		auto trans = findBook_v2(files, book);		// 销售了这本书的书店
		if (trans.empty())
		{
			cout << book << " not found in any store" << endl;
			continue;
		}
		for (const auto& store : trans)			// 对每家销售了给定书籍的书店
		{
			os << "store " << store.first << " sales: "
				<< accumulate(store.second.first, store.second.second, Sales_data(book))
				<< endl;
		}
	}
}

/*

练习 17.6：重写 findBook，不使用 tuple 或 pair

*/

// 定义一个 struct 来存储返回信息
struct matches_v3{
	vector<vector<Sales_data>>::size_type storeId;
	vector<Sales_data>::const_iterator beg_iter;
	vector<Sales_data>::const_iterator end_iter;

	matches_v3(vector<vector<Sales_data>>::size_type storeId_,
			   vector<Sales_data>::const_iterator beg_iter_,
			   vector<Sales_data>::const_iterator end_iter_)
		: storeId(storeId_), beg_iter(beg_iter_), end_iter(end_iter_)
	{
	}

};

vector<matches_v3>
findBook_v3(const vector<vector<Sales_data>>& files,
			const string& book)
{
	vector<matches_v3> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
		{
			ret.push_back(matches_v3(it - files.cbegin(), found.first, found.second));
		}
	}

	return ret;
}

void reportResult_v3(istream& in, ostream& os, const vector<vector<Sales_data>>& files)
{
	string book;
	while (in >> book)
	{
		auto trans = findBook_v3(files, book);		// 销售了这本书的书店
		if (trans.empty())
		{
			cout << book << " not found in any store" << endl;
			continue;
		}
		for (const auto& store : trans)			// 对每家销售了给定书籍的书店
		{
			os << "store " << store.storeId << " sales: "
				<< accumulate(store.beg_iter, store.end_iter, Sales_data(book))
				<< endl;
		}
	}
}


int main()
{
	vector<Sales_data> storeA;
	vector<Sales_data> storeB;
	vector<Sales_data> storeC;
	storeA.push_back(Sales_data("Hungry", 4, 50));
	storeA.push_back(Sales_data("HarryPotter", 3, 100));
	storeA.push_back(Sales_data("Hungry", 10, 78));
	storeA.push_back(Sales_data("MoonLightBlade", 7, 77));
	storeA.push_back(Sales_data("Hungry", 3, 90));

	storeB.push_back(Sales_data("MoonLightBlade", 9, 80));
	storeB.push_back(Sales_data("MoonLightBlade", 3, 100));
	storeB.push_back(Sales_data("SteveJobs", 3, 999));

	storeC.push_back(Sales_data("Hungry", 1, 100));
	storeC.push_back(Sales_data("SteveJobs", 1, 1000));
	storeC.push_back(Sales_data("Hungry", 2, 120));

	// 将每个商店的销售记录按照书名排序
	sort(storeA.begin(), storeA.end(), compareIsbn);
	sort(storeB.begin(), storeB.end(), compareIsbn);
	sort(storeC.begin(), storeC.end(), compareIsbn);
	
	// 构建出 files，保存每家书店的销售记录
	vector<vector<Sales_data>> files { storeA, storeB, storeC };

	// 交互
	//reportResult(cin, cout, files);
	//reportResult_v2(cin, cout, files);
	reportResult_v3(cin, cout, files);

	return 0;
}

/*

Hungry
store 0 sales: Hungry 17 1250 73.5294
store 2 sales: Hungry 3 340 113.333
Hary
Hary not found in any store
SteveJobs
store 1 sales: SteveJobs 3 2997 999
store 2 sales: SteveJobs 1 1000 1000
^Z
请按任意键继续. . .

*/
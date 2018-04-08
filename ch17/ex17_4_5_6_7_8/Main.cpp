/*
��ϰ 17.4����д���������Լ��汾�� findBook ����
��ϰ 17.5����д findBook�����䷵��һ�� pair������һ��������һ�������� pair
��ϰ 17.6����д findBook����ʹ�� tuple �� pair
��ϰ 17.7����������������Ǹ��汾�� findBook��Ϊʲô��

�������� tuple �汾�ģ���������Ҳ�Ƚ�������⡣
struct �汾����������⣬����д�����Ƚφ��¡�

��ϰ 17.8���ڱ������һ�δ����У�������ǽ� Sales_data() ��Ϊ�������������ݸ� accumulate���ᷢ��ʲô��
����� Sales_data() ��Ϊ����������������� Sales_data ��Ĭ�Ϲ��캯����������� Sales_data ����

bookNo = string("")
units_sold = 0;
revenue = 0.0;

��Ӱ�� accumulate ���������㣬�����ǿ��Եġ�

*/

#include "Sales_data.h"
#include <tuple>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

// ʹ�� tuple ���ض��ֵ

// vector<vector<Sales_data>> files;
// ��д����������һ���������飬�� files ���������۹��Ȿ�����ꡣ
// ��ÿ����ƥ�����ۼ�¼����꣬���Ǵ���һ�� tuple �������������������������������

// matches ��������Ա��һ������������������ָ����� vector ��Ԫ�صĵ�����
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
		auto trans = findBook(files, book);		// �������Ȿ������
		if (trans.empty())
		{
			cout << book << " not found in any store" << endl;
			continue;
		}
		for (const auto& store : trans)			// ��ÿ�������˸����鼮�����
		{
			os << "store " << get<0>(store) << " sales: "
				<< accumulate(get<1>(store), get<2>(store), Sales_data(book))
				<< endl;
		}
	}
}

/*

��ϰ 17.5����д findBook�����䷵��һ�� pair������һ��������һ�������� pair

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
		auto trans = findBook_v2(files, book);		// �������Ȿ������
		if (trans.empty())
		{
			cout << book << " not found in any store" << endl;
			continue;
		}
		for (const auto& store : trans)			// ��ÿ�������˸����鼮�����
		{
			os << "store " << store.first << " sales: "
				<< accumulate(store.second.first, store.second.second, Sales_data(book))
				<< endl;
		}
	}
}

/*

��ϰ 17.6����д findBook����ʹ�� tuple �� pair

*/

// ����һ�� struct ���洢������Ϣ
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
		auto trans = findBook_v3(files, book);		// �������Ȿ������
		if (trans.empty())
		{
			cout << book << " not found in any store" << endl;
			continue;
		}
		for (const auto& store : trans)			// ��ÿ�������˸����鼮�����
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

	// ��ÿ���̵�����ۼ�¼������������
	sort(storeA.begin(), storeA.end(), compareIsbn);
	sort(storeB.begin(), storeB.end(), compareIsbn);
	sort(storeC.begin(), storeC.end(), compareIsbn);
	
	// ������ files������ÿ���������ۼ�¼
	vector<vector<Sales_data>> files { storeA, storeB, storeC };

	// ����
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
�밴���������. . .

*/
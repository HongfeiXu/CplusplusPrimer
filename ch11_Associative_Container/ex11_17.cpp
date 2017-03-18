/*
	练习 11.17：假定 c 是一个 string 的 multiset，v 是一个 string 的 vector，解释下面的调用。指出每个调用是否合法。
*/


#include <vector>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	multiset<string> multiSetString { "Micheal", "Jordan", "Roger" };
	vector<string> vecString { "Alex", "Bobo" };

	// 调用 1 合法
	//copy(vecString.begin(), vecString.end(), inserter(multiSetString, multiSetString.end()));

	//for(const auto & item : multiSetString)
	//{
	//	cout << item << endl;
	//}

	// 调用 2 非法
	// error C2039: 'push_back': is not a member of 'std::multiset<std::string,std::less<_Kty>,std::allocator<_Kty>>'
	//copy(vecString.begin(), vecString.end(), back_inserter(multiSetString));

	//for(const auto & item : multiSetString)
	//{
	//	cout << item << endl;
	//}

	// 调用 3 合法
	//copy(multiSetString.begin(), multiSetString.end(), inserter(vecString, vecString.end()));
	//
	//for(const auto & item : vecString)
	//	cout << item << endl;

	// 调用 4 合法
	copy(multiSetString.begin(), multiSetString.end(), back_inserter(vecString));

	for(const auto & item : vecString)
		cout << item << endl;

	return 0;
}

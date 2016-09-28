/*
* 练习 9.43：编写一个函数，接受三个 string 参数 s、oldVal 和 newVal。使用迭代器以及 insert 和 erase 函数将 s 中所有 oldVal 替换为 newVal。
*/

#include <iostream>
#include <string>
using namespace std;

void replaceOldValWithNewVal(string &s, const string &oldVal, const string &newVal);
void replaceOldValWithNewVal_2(string &s, const string &oldVal, const string &newVal);

int main()
{
	string s("even tho you are just a little girl, I love your. tho");
	string oldVal("tho");
	string newVal("though");
	replaceOldValWithNewVal_2(s, oldVal, newVal);
	cout << s << endl;
	replaceOldValWithNewVal(s, oldVal, newVal);
	cout << s << endl;

	return 0;
}


void replaceOldValWithNewVal(string &s, const string &oldVal, const string &newVal)
{
	for(auto iteratorS = s.cbegin(); iteratorS <= s.cend() - oldVal.size(); )
	{
		auto temp = iteratorS;
		auto iteratorOldVal = oldVal.cbegin();
		for(iteratorOldVal; ((iteratorOldVal != oldVal.cend()) && *temp == *iteratorOldVal); ++iteratorOldVal, ++temp)
			;
		if(iteratorOldVal == oldVal.cend())
		{
			iteratorS = s.erase(iteratorS, iteratorS + oldVal.size());
			iteratorS = s.insert(iteratorS, newVal.cbegin(), newVal.cend());
			iteratorS += newVal.size();
		}
		else
			++iteratorS;
	}
}

// 判断串相同的条件更直观
void replaceOldValWithNewVal_2(string &s, const string &oldVal, const string &newVal)
{
	for(auto cur = s.begin(); cur <= s.end() - oldVal.size(); )
	{
		if(oldVal == string(cur, cur + oldVal.size()))		// 创建了一个临时 string 对象
		{
			cur = s.erase(cur, cur + oldVal.size());
			cur = s.insert(cur, newVal.cbegin(), newVal.cend());		// 插入位置之后的迭代器失效，需要重新加载
			cur += newVal.size();
		}
		else
			++cur;
	}
}


/*

even though you are just a little girl, I love your. though
even thoughugh you are just a little girl, I love your. thoughugh
请按任意键继续. . .

*/
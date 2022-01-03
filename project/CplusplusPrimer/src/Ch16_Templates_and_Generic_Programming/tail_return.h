#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <type_traits>

using namespace std;

/*

16.2.3 β�÷�������������ת��

*/


template<typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
	return *beg;	// ����������һ��Ԫ�ص�����
}

template<typename It>
auto fcn2(It beg, It end) -> typename remove_reference<decltype(*beg)>::type
{
	return *beg;	// ����������һ��Ԫ�صĿ���
}


void test()
{
	vector<int> vi = { 1,2,3,4 };
	auto it = fcn(vi.begin(), vi.end());
	cout << it << endl;

	list<string> ls = { "hello", "world" };
	cout << fcn2(ls.begin(), ls.end()) << endl;
}
/*
* ��ϰ6.27����дһ�����������Ĳ����� initializer_list<int> ���͵Ķ��󣬺����Ĺ����Ǽ����б�������Ԫ�صĺ͡�
*/

#include <iostream>
#include <initializer_list>

using std::initializer_list;
using std::cout;
using std::cin;
using std::endl;

int sum (initializer_list<int> intList)
{
	int ret = 0;
	for (auto item : intList)
		ret += item;
	return ret;
}

int main ()
{
	cout << sum ({ 1, 2, 3, 4, 5 }) << endl;
	cout << sum ({ 6, 7, 8, 9, 10 }) << endl;
	return 0;
}


/*

15
40
�밴���������. . .

*/
/*
* ��ϰ6.37��6.38����д����������ʹ�䷵����������ã����Ҹ��������10��string����
*/

#include <iostream>
#include <string>
#include <vector>

using std::string;

typedef string arrT[10];		// arrT��һ��������������ʾ�������Ǻ���10�����������顣
using arrT_2 = string[10];	// ������ĵȼ�

arrT_2 &func1 (arrT_2 &arr);

string (&func2 (arrT_2 &arr))[10];

auto func3 (arrT_2 &arr)->string (&)[10];

string arr[10];

decltype(arr) &func4 ();
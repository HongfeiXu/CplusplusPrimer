/*
* 练习6.37、6.38：编写函数声明。使其返回数组的引用，并且该数组包含10个string对象。
*/

#include <iostream>
#include <string>
#include <vector>

using std::string;

typedef string arrT[10];		// arrT是一个类型名，它表示的类型是含有10个整数的数组。
using arrT_2 = string[10];	// 与上面的等价

arrT_2 &func1 (arrT_2 &arr);

string (&func2 (arrT_2 &arr))[10];

auto func3 (arrT_2 &arr)->string (&)[10];

string arr[10];

decltype(arr) &func4 ();
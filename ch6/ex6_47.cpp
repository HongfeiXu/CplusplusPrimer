/*
* 练习6.47：改写p205练习中使用递归输出vector内容的程序，使其有条件的输出与执行过程有关的信息。
* 例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。
*/

#include <iostream>
#include <string>
#include <vector>

#define NDEBUG		// 等价于编译时语句 cl /EHsc /D NDEBUG main.cpp

using std::vector;
using std::string;
using std::cout;
using std::endl;

void printVector (vector<string>::iterator sbeg, vector<string>::iterator send)
{
#ifndef NDEBUG
	cout << "\nvector size: " << send - sbeg << endl;
#endif
	if (sbeg == send)
	{
		cout << endl;
		return;
	}
	cout << *sbeg << " ";
	sbeg += 1;
	printVector (sbeg, send);
}

int main ()
{
	vector<string> sv = { "hello", "world", "wow", "hey" };
	printVector (sv.begin (), sv.end ());
	return 0;
}

/*

I:\vs\cplusplus\cplusplus>cl /EHsc main.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

main.cpp
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj

I:\vs\cplusplus\cplusplus>main

vector size: 4
hello
vector size: 3
world
vector size: 2
wow
vector size: 1
hey
vector size: 0

I:\vs\cplusplus\cplusplus>cl /EHsc /D NDEBUG main.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

main.cpp
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj

I:\vs\cplusplus\cplusplus>main
hello world wow hey



*/
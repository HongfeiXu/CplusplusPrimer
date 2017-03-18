/*
* 练习6.9：编写你自己的fact.cc和factMain.cc，这两个文件应该包含上一小节练习中编写的Chapter6.h头文件。
* 通过这些文件，理解你的编译器是如何支持分离式编译的。
*/

#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;


int main ()
{
	int val = askUser ();
	cout << fact (val) << endl;

	return 0;
}


/*

I:\vs\cplusplus\cplusplus>cl /EHsc main.cpp fact.cpp askUser.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

main.cpp
fact.cpp
askUser.cpp
正在生成代码...
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj
fact.obj
askUser.obj

I:\vs\cplusplus\cplusplus>main
Please enter a number: 10
3628800


分离式编译===================================

I:\vs\cplusplus\cplusplus>cl /EHsc -c main.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

main.cpp

I:\vs\cplusplus\cplusplus>cl /EHsc -c fact.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

fact.cpp

I:\vs\cplusplus\cplusplus>cl /EHsc -c askUser.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

askUser.cpp

I:\vs\cplusplus\cplusplus>cl main.obj fact.obj askUser.obj
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj
fact.obj
askUser.obj

I:\vs\cplusplus\cplusplus>main
Please enter a number: 10
3628800

*/
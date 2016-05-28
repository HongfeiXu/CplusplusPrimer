
/*
* 练习1.2：改写程序，让它返回-1，返回值-1通常被当做程序错误的标识。
* 重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。
*/
int main ()
{
	return -1;
}

/*


I:\vs\learnCplus\learnCplus>cl /EHsc /W4 main.cpp
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.00.23918 版
版权所有(C) Microsoft Corporation。保留所有权利。

main.cpp
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj

I:\vs\learnCplus\learnCplus>main

I:\vs\learnCplus\learnCplus>echo %ERRORLEVEL%
-1

I:\vs\learnCplus\learnCplus>


*/

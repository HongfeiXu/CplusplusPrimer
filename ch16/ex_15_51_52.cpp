#include <iostream>
#include "util.h"

using namespace std;

template<typename T, typename... Args>
void foo(T t, Args ...args)
{
	cout << sizeof...(Args) << endl;
	cout << sizeof...(args) << endl;
}

int main()
{
	foo(1, "hello", 234);
	foo(123, "wlo", 123123, 123);
	return 0;
}

/*
2
2
3
3

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (���� 17896)���˳�������Ϊ 0��
��������رմ˴���. . .
*/

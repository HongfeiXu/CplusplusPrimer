/*
* ��ϰ1.21����д���򣬶�ȡ����ISBN��ͬ��Sales_item����������ǵĺ͡�
*/

#include <iostream>
#include "Sales_item.h"

int main ()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	std::cout << item1 + item2 << std::endl;

	return 0;
}

/*

�ļ�add_item����
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00 

F:\CplusplusPrimer\ch1>cl /EHsc /W4 ex1_21.cpp
���� x86 �� Microsoft (R) C/C++ �Ż������� 19.00.23918 ��
��Ȩ����(C) Microsoft Corporation����������Ȩ����

ex1_21.cpp
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:ex1_21.exe
ex1_21.obj

F:\CplusplusPrimer\ch1>ex1_21 < data\add_item
0-201-78345-X 5 110 22

F:\CplusplusPrimer\ch1>

*/
/*
* ��ϰ1.20����ȡһ���鼮���ۼ�¼����ÿ����¼��ӡ����׼�����
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item book;
	while (std::cin >> book)
	{
		std::cout << book << std::endl;
	}
	
	return 0;
}

/*

F:\CplusplusPrimer\ch1>cl /EHsc /W4 ex1_20.cpp
���� x86 �� Microsoft (R) C/C++ �Ż������� 19.00.23918 ��
��Ȩ����(C) Microsoft Corporation����������Ȩ����

ex1_20.cpp
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:ex1_20.exe
ex1_20.obj

F:\CplusplusPrimer\ch1>ex1_20 < data\book_sales
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 2 30 15
0-201-88954-4 5 60 12
0-201-88954-4 7 84 12
0-201-88954-4 2 24 12
0-399-82477-1 2 90.78 45.39
0-399-82477-1 3 136.17 45.39
0-201-78345-X 3 60 20
0-201-78345-X 2 50 25

F:\CplusplusPrimer\ch1>

*/
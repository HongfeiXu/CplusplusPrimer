/*
* ��ϰ1.5����д����1.4����ÿ���������Ĵ�ӡ��������һ������������С�
*/


#include <iostream>

int main ()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The product of ";
	std::cout << v1;
	std::cout << " and ";
	std::cout << v2;
	std::cout << " is ";
	std::cout << v1 * v2;
	std::cout << std::endl;


	return 0;
}

/*

F:\CplusplusPrimerCode\ch01>cl /EHsc /W4 ex1_5.cpp
���� x86 �� Microsoft (R) C/C++ �Ż������� 19.00.23918 ��
��Ȩ����(C) Microsoft Corporation����������Ȩ����

ex1_5.cpp
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:ex1_5.exe
ex1_5.obj

F:\CplusplusPrimerCode\ch01>ex1_5.cpp

F:\CplusplusPrimerCode\ch01>ex1_5
Enter two numbers:
3 10
The product of 3 and 10 is 30

F:\CplusplusPrimerCode\ch01>

*/

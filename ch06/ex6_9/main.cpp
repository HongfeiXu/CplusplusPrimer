/*
* ��ϰ6.9����д���Լ���fact.cc��factMain.cc���������ļ�Ӧ�ð�����һС����ϰ�б�д��Chapter6.hͷ�ļ���
* ͨ����Щ�ļ��������ı����������֧�ַ���ʽ����ġ�
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
���� x86 �� Microsoft (R) C/C++ �Ż������� 19.00.23918 ��
��Ȩ����(C) Microsoft Corporation����������Ȩ����

main.cpp
fact.cpp
askUser.cpp
�������ɴ���...
Microsoft (R) Incremental Linker Version 14.00.23918.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj
fact.obj
askUser.obj

I:\vs\cplusplus\cplusplus>main
Please enter a number: 10
3628800


����ʽ����===================================

I:\vs\cplusplus\cplusplus>cl /EHsc -c main.cpp
���� x86 �� Microsoft (R) C/C++ �Ż������� 19.00.23918 ��
��Ȩ����(C) Microsoft Corporation����������Ȩ����

main.cpp

I:\vs\cplusplus\cplusplus>cl /EHsc -c fact.cpp
���� x86 �� Microsoft (R) C/C++ �Ż������� 19.00.23918 ��
��Ȩ����(C) Microsoft Corporation����������Ȩ����

fact.cpp

I:\vs\cplusplus\cplusplus>cl /EHsc -c askUser.cpp
���� x86 �� Microsoft (R) C/C++ �Ż������� 19.00.23918 ��
��Ȩ����(C) Microsoft Corporation����������Ȩ����

askUser.cpp

I:\vs\cplusplus\cplusplus>cl main.obj fact.obj askUser.obj
���� x86 �� Microsoft (R) C/C++ �Ż������� 19.00.23918 ��
��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
/*
* ��ϰ6.8����дһ����ΪChapter6.h��ͷ�ļ����������6.1����ϰ�еĺ���������
*/

// �ļ�Chapter.h����
#ifndef CHAPTER_6_H
#define CHAPTER_6_H

int fact (int val);
int askuser ();


#endif // !CHAPTER_6_H

// �ļ�main.c�е�����

#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;


int main ()
{
	int val = askuser ();
	cout << fact (val) << endl;

	return 0;
}

int fact (int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}

int askuser ()
{
	int val;
	cout << "Please enter a number: ";
	cin >> val;
	return val;
}


/*

Please enter a number: 5
120
�밴���������. . .

*/
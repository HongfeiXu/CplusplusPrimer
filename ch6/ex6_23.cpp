/*
* ��ϰ6.23���ο����ڽ��ܵļ���print��������������д���Լ��İ汾��
* ���ε���ÿ������ʹ���������涨��� i �� j��
* int i = 0, j[2] = {0, 1};
*/

#include <iostream>
#include <iterator>

using std::begin;
using std::end;
using std::cout;
using std::cin;
using std::endl;

void print (const char *cp)
{
	if (cp)
		while (*cp)
			cout << *cp++;
	cout << endl;
}

void print (const int *pi)
{
	if (pi)
		cout << *pi << endl;
}

void print (const int *beg, const int *end)
{
	while (beg != end)
	{
		cout << *beg++;
	}
	cout << endl;
}

void print (const int ia[], size_t size)
{
	for (size_t i = 0; i != size; ++i)
	{
		cout << ia[i];
	}
	cout << endl;
}

void print (int (&a)[2])
{
	for (auto elem : a)
	{
		cout << elem;
	}
	cout << endl;
}

int main ()
{
	int i = 0, j[2] = { 0, 1 };
	char ch[5] = "Alex";
	print (ch);
	print (&i);
	print (begin (j), end(j));
	print (j, end (j) - begin (j));
//	print (j);		// �ж������������б�ƥ�䡣

	return 0;
}


/*

Alex
0
01
01
�밴���������. . .

*/
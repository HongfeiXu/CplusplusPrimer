/*
* ��ϰ6.38���޸� arrPtr ������ʹ�䷵����������á�
*/

#include <iostream>

using std::cout;
using std::endl;

int odd[] = { 1, 3, 5, 7, 9 };
int even[] = { 0, 2, 4, 6, 8 };

inline decltype(odd) &attPtr (int i)
{
	return (i % 2) ? odd : even;
}

int main ()
{
	int (&ptr)[5] = attPtr (3);
	for (auto item : ptr)
		cout << item << " ";
	cout << endl;
	return 0;
}

/*

1 3 5 7 9
�밴���������. . .

*/
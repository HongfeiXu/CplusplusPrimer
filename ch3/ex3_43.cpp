/*
* ��ϰ3.43 3.44 3.45 ��д��ͬ�汾�ĳ��������ά��������ݡ�
*/

#include <iostream>
#include <iterator>

using std::begin;
using std::end;
using std::cout;
using std::endl;

int main ()
{
	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia[rowCnt][colCnt];
	for (size_t i = 0; i != rowCnt; i++)
		for (size_t j = 0; j != colCnt; j++)
			ia[i][j] = i * colCnt + j;
	
	cout << "ʹ�� range for �������������" << endl;
	for (const auto &row : ia)		// �˴�����Ϊ��������
	{
		for (auto col : row)
			cout << col << ' ';
		cout << endl;
	}
	cout << "ʹ���±������" << endl;
	for (size_t i = 0; i != rowCnt; i++)
	{
		for (size_t j = 0; j != colCnt; j++)
			cout << ia[i][j] << ' ';
		cout << endl;
	}
	cout << "ʹ��ָ��" << endl;
	for (int (*p)[4] = ia; p != ia + 3; ++p)
	{
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}

	cout << "ʹ��������������ѭ�����Ʊ��������͡�" << endl;
	using int_array = int[4];	// ���ͱ���������
	for (int_array *p = ia; p != ia + 3; ++p)
	{
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}

	cout << "ʹ��auto�ؼ���" << endl;
	for (auto p = ia; p != ia + 3; ++p)
	{
		for (auto q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}

	cout << "ʹauto�ؼ����Լ���׼�⺯�� begin �� end" << endl;
	for (auto p = begin (ia); p != end (ia); ++p)
	{
		for (auto q = begin (*p); q != end (*p); ++q)
			cout << *q << ' ';
		cout << endl;
	}

	return 0;
}

/*

ʹ�� range for �������������
0 1 2 3
4 5 6 7
8 9 10 11
ʹ���±������
0 1 2 3
4 5 6 7
8 9 10 11
ʹ��ָ��
0 1 2 3
4 5 6 7
8 9 10 11
ʹ��������������ѭ�����Ʊ��������͡�
0 1 2 3
4 5 6 7
8 9 10 11
ʹ��auto�ؼ���
0 1 2 3
4 5 6 7
8 9 10 11
ʹauto�ؼ����Լ���׼�⺯�� begin �� end
0 1 2 3
4 5 6 7
8 9 10 11
�밴���������. . .


*/
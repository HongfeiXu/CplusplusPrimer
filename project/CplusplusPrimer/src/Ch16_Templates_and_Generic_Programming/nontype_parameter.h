#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ����ģ�����
template <typename T>
int compare(const T& v1, const T& v2)
{
	if (v1 < v2)
		return -1;
	if (v2 < v1)
		return 1;
	return 0;
}

// ������ģ�����
template<unsigned N, unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M])		// // ����ı����ǳ������ʽ
{
	cout << N << " " << M << endl;	// �������ƶϳ� N �� M ��ֵ
	return strcmp(p1, p2);
}

// ���ڷ�����ģ�������Ӧ��

/// <summary>
/// ��ӡ��������
/// �ɴ��������С��Ԫ�����͵�����
/// </summary>
template<typename T, unsigned N>
void print(const T(&arr)[N])	// ���������β�
{
	copy(std::cbegin(arr), std::cend(arr), ostream_iterator<T>(cout, " "));
}

/// <summary>
/// ���ظ��������С�����ص��ǳ������ʽ�������ھ��ܵõ������
/// </summary>
template <typename T, unsigned N>
constexpr unsigned getArraySize(const T(&arr)[N])
{
	return N;
}


void test()
{
	float fa = 1.2f;
	float fb = 1.3f;
	cout << compare(fa, fb) << endl;

	cout << compare("hi", "mom") << endl;	// ����ı����ǳ������ʽ

	int arr[] = { 1,2,3,4,5,6 };
	print(arr);
	cout << endl;

	cout << getArraySize(arr) << endl;
	
	// ֻ�е� getArraySize ���س������ʽʱ��������ǶԵģ�
	// ���򱨴�����δ����ĺ�����Ϊδ����Ϊ��constexpr���ĺ����ĵ��õ����˹��ϡ�
	int arrb[getArraySize(arr)];
}

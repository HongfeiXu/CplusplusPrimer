/*
* 练习3.43 3.44 3.45 编写不同版本的程序，输出二维数组的内容。
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
	
	cout << "使用 range for 语句管理迭代过程" << endl;
	for (const auto &row : ia)		// 此处必须为引用类型
	{
		for (auto col : row)
			cout << col << ' ';
		cout << endl;
	}
	cout << "使用下标运算符" << endl;
	for (size_t i = 0; i != rowCnt; i++)
	{
		for (size_t j = 0; j != colCnt; j++)
			cout << ia[i][j] << ' ';
		cout << endl;
	}
	cout << "使用指针" << endl;
	for (int (*p)[4] = ia; p != ia + 3; ++p)
	{
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}

	cout << "使用类型名来代替循环控制变量的类型。" << endl;
	using int_array = int[4];	// 类型别名的声明
	for (int_array *p = ia; p != ia + 3; ++p)
	{
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}

	cout << "使用auto关键字" << endl;
	for (auto p = ia; p != ia + 3; ++p)
	{
		for (auto q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}

	cout << "使auto关键字以及标准库函数 begin 和 end" << endl;
	for (auto p = begin (ia); p != end (ia); ++p)
	{
		for (auto q = begin (*p); q != end (*p); ++q)
			cout << *q << ' ';
		cout << endl;
	}

	return 0;
}

/*

使用 range for 语句管理迭代过程
0 1 2 3
4 5 6 7
8 9 10 11
使用下标运算符
0 1 2 3
4 5 6 7
8 9 10 11
使用指针
0 1 2 3
4 5 6 7
8 9 10 11
使用类型名来代替循环控制变量的类型。
0 1 2 3
4 5 6 7
8 9 10 11
使用auto关键字
0 1 2 3
4 5 6 7
8 9 10 11
使auto关键字以及标准库函数 begin 和 end
0 1 2 3
4 5 6 7
8 9 10 11
请按任意键继续. . .


*/
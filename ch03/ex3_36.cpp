/*
* 练习3.36： 编写一段程序，比较两个数组是否相等。
*/

#include <iostream>
#include <iterator>
#include <vector>

using std::vector;
using std::begin;
using std::end;
using std::cout;
using std::cin;
using std::endl;

bool compare (int *const pb1, int *const pe1, int *const pb2, int *const pe2)
{
	if ((pe1 - pb1) != (pe2 - pb2))		// have different size
		return false;
	else
	{
		for (int *i = pb1, *j = pb2; i != pe1; i++, j++)
		{
			if (*i != *j)			// have different value
				return false;
		}
	}
	return true;
}

int main ()
{
	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 1, 3, 4 };
	
	if (compare (begin (arr1), end (arr1), begin (arr2), end (arr2)))
		cout << "The two arrays are equal." << endl;
	else
		cout << "The two arrays are not equal." << endl;

	cout << "==================" << endl;
	
	vector<int> vec1 = { 1, 2, 3 };
	vector<int> vec2 = { 1, 2, 3 };
	if (vec1 == vec2)
		cout << "The two vectors are equal." << endl;
	else
		cout << "The two vectors are not equal." << endl;

	return 0;
}

/*

The two arrays are not equal.
==================
The two vectors are equal.
请按任意键继续. . .

*/
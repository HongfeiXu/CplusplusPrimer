/*
* ��ϰ3.41����дһ�γ��������������ʼ��һ��vector����
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


int main ()
{
	int int_arr[] = { 0, 1, 2, 3, 4 , 5 };
	vector<int> ivec (begin (int_arr), end (int_arr));
	for (auto i : ivec)
		cout << i << " ";
	cout << endl;
	
	return 0;
}

/*

0 1 2 3 4 5
�밴���������. . .

*/
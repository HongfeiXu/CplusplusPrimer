/*
*	练习 9.47：编写程序，首先查找 string "ab2c3d7R4E6" 中的每个数字字符，然后查找其中每个字母字符。
*	编写两个版本的程序，第一个要使用 find_first_of，第二个要使用 find_first_not_of。
*	版本1
*/


#include <string>
#include <iostream>

using namespace std;


int main()
{
	string s("ab2c3d7R4E6");
	string numbers("0123456789");
	string letters("zxcvbnmasdfghjklqwertyuiopZXCVBNMASDFGHJKLQWERTYUIOP");

	string::size_type pos = 0;
	while((pos = s.find_first_of(numbers, pos)) != string::npos)
	{
		cout << "found number at index: " << pos
			<< " element is " << s[pos] << endl;
		++pos;
	}

	pos = 0;
	while((pos = s.find_first_of(letters, pos)) != string::npos)
	{
		cout << "found letter at index: " << pos
			<< " element is " << s[pos] << endl;
		++pos;
	}


	return 0;
}

/*

found number at index: 2 element is 2
found number at index: 4 element is 3
found number at index: 6 element is 7
found number at index: 8 element is 4
found number at index: 10 element is 6
found letter at index: 0 element is a
found letter at index: 1 element is b
found letter at index: 3 element is c
found letter at index: 5 element is d
found letter at index: 7 element is R
found letter at index: 9 element is E
请按任意键继续. . .

*/
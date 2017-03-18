/*
* 例子 p190
* 定义一个名为find_char的函数，返回在string对象中某个指定字符第一次出现的位置。
* 同时我们也希望函数能返回该字符出现的总次数。
*/

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

string::size_type findChar (const string &s, char c, string::size_type &occurs)
{
	string::size_type ret = s.size ();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size (); ++i)
	{
		if (s[i] == c)
		{
			if (ret == s.size ())
				ret = i;
			++occurs;
		}
	}
	return ret;
}

int main ()
{
	string s = "Hello World!";
	string::size_type occurs = 0, firstShow = 0;
	firstShow = findChar (s, 'o', occurs);
	cout << "o occurs " << occurs << " times" << " in string " << s << endl;
	cout << "the first position o show up is index " << firstShow << endl;
	  
	return 0;
}
 

/*

o occurs 2 times in string Hello World!
the first position o show up is index 4
请按任意键继续. . .

*/
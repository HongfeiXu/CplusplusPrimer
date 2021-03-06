/*
* 练习3.40：编写一段程序，定义两个字符数组并用字符串字面值初始化它们；
* 接着在定义一个字符数组存放前两个数组连接后的结果。
* 使用strcpy和strcat把前两个数组的内容拷贝到第三个数组中。
*/

#include <iostream>
#include <cstring>

using std::cout; 
using std::endl;

constexpr size_t constexpr_strlen (const char *s)
{
	return sizeof (s) / sizeof (*s);			// sizeof返回一个常量表达式
}


constexpr size_t merge_size (const char* cs1, const char* cs2)
{
	return constexpr_strlen (cs1) + constexpr_strlen (" ") + constexpr_strlen (cs2) + 1;		// 使用strlen不行
}

int main ()
{
	constexpr const char cs1[] = "Hi";
	constexpr const char cs2[] = "frank67";
	char cs3[merge_size (cs1, cs2)];
	strcpy (cs3, cs1);
	strcat (cs3, " ");
	strcat (cs3, cs2);
	cout << cs3 << endl;
	return 0;
}

/*

Hi frank67
请按任意键继续. . .

*/
/*

练习 12.24：编写一个程序，从标准输入中读取一个字符串，存入一个动态分配的字符数组中。
描述你的程序如何处理变长输入。测试你的程序，输入一个超出你分配的数组长度的字符串。

*/

#include <iostream>

using namespace std;

int main()
{
	cout << "How long do you want the string?";
	int size(0);
	cin >> size;
	char *const input = new char[size + 1]();
	cin.ignore();  // 读取并忽略一个字符 '\n'
	cout << "input the string: ";
	cin.get(input, size + 1);
	cout << input << endl;
	delete[] input;
	
	return 0;
}

/*

How long do you want the string?4
input the string: Hello
Hell
Press any key to continue . . .

*/
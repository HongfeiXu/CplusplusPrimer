/*
* 练习4.28：编写一段程序，输出每一种内置类型所占空间的大小。
*/

#include <iostream>
#include <string>
#include <vector>

using std::cout; 
using std::endl;


int main ()
{
	// void type
	cout << "void: nullptr_t\t" << sizeof (nullptr_t) << "bytes\n" << endl;

	// boolean type
	cout << "bool:\t\t" << sizeof (bool) << "bytes\n" << endl;

	// character type
	cout << "char:\t\t" << sizeof (char) << "bytes\n" << endl;
	cout << "wchar_t:\t" << sizeof (wchar_t) << "bytes\n" << endl;
	cout << "char16_t:\t" << sizeof (char16_t) << "bytes\n" << endl;
	cout << "char32_t:\t" << sizeof (char32_t) << "bytes\n" << endl;

	// integer type
	cout << "short:\t\t" << sizeof (short) << "bytes\n" << endl;
	cout << "int:\t\t" << sizeof (int) << "bytes\n" << endl;
	cout << "long:\t\t" << sizeof (long) << "bytes\n" << endl;
	cout << "long long:\t" << sizeof (long long) << "bytes\n" << endl;

	// floating point type
	cout << "float:\t\t" << sizeof (float) << "bytes\n" << endl;
	cout << "double:\t\t" << sizeof (double) << "bytes\n" << endl;
	cout << "long double:\t" << sizeof (long double) << "bytes\n" << endl;

	// Fixed width integers
	cout << "int8_t:\t\t" << sizeof (int8_t) << "bytes\n" << endl;
	cout << "uint8_t:\t" << sizeof (uint8_t) << "bytes\n" << endl;
	cout << "int16_t:\t" << sizeof (int16_t) << "bytes\n" << endl;
	cout << "uint16_t:\t" << sizeof (uint16_t) << "bytes\n" << endl;
	cout << "int32_t:\t" << sizeof (int32_t) << "bytes\n" << endl;
	cout << "uint32_t:\t" << sizeof (uint32_t) << "bytes\n" << endl;
	cout << "int64	_t:\t" << sizeof (int64_t) << "bytes\n" << endl;
	cout << "uint64_t:\t" << sizeof (uint64_t) << "bytes\n" << endl;

	return 0;
}

/*

void: nullptr_t 4bytes

bool:           1bytes

char:           1bytes

wchar_t:        2bytes

char16_t:       2bytes

char32_t:       4bytes

short:          2bytes

int:            4bytes

long:           4bytes

long long:      8bytes

float:          4bytes

double:         8bytes

long double:    8bytes

int8_t:         1bytes

uint8_t:        1bytes

int16_t:        2bytes

uint16_t:       2bytes

int32_t:        4bytes

uint32_t:       4bytes

int64   _t:     8bytes

uint64_t:       8bytes

请按任意键继续. . .

*/
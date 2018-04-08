#include <iostream>
#include <vector>
#include <utility>
#include "String.h"


using namespace std;

int main()
{
	std::vector<String> svec;
	svec.push_back("Hello");
	svec.push_back("World");
	
	String s("Wow");
	svec.push_back(s);

	return 0;
}

/*

String::Constructor
String::MoveConstructor
String::Constructor
String::MoveConstructor
String::MoveConstructor
String::Constructor
String::MoveConstructor
String::MoveConstructor
String::CopyConstructor
请按任意键继续. . .

*/
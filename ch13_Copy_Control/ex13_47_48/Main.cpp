#include <iostream>
#include "String.h"
#include <vector>

using namespace std;

int main()
{
	std::vector<String> svec;
	svec.push_back("Hello");
	svec.push_back("World");


	return 0;
}

/*

// windows 10, visual studio 2015


run Constructor s: Hello
run Copy Constructor rhs: Hello
run Desturctor c_str(): Hello
run Constructor s: World
run Copy Constructor rhs: Hello
run Desturctor c_str(): Hello
run Copy Constructor rhs: World
run Desturctor c_str(): World
run Desturctor c_str(): Hello
run Desturctor c_str(): World
请按任意键继续. . .

*/
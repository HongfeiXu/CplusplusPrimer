#include "HasPtr.h"
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	HasPtr hp1("Lebron", 1);
	vector<HasPtr> cont;
	cont.push_back(hp1);
	cont.push_back(hp1);
	cont.push_back(string("hello"));
	cout << cont.capacity() << endl;

	HasPtr hp3;
	hp3 = hp1;

	HasPtr hp4;
	hp4 = move(hp1);



	return 0;
}

/*

HasPtr::CopyConstructor
HasPtr::MoveConstructor
HasPtr::CopyConstructor
HasPtr::MoveConstructor
HasPtr::MoveConstructor
HasPtr::MoveConstructor
3
HasPtr::CopyConstructor
HasPtr::swap()
HasPtr::MoveConstructor
HasPtr::swap()
请按任意键继续. . .


*/
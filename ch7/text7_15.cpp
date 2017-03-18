/*
* test ex7_15.h
*/

#include <string>
#include "ex7_15.h"
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main ()
{
	Person p1;
	print (cout, p1) << endl;
	Person p2 (cin);
	print (cout, p2) << endl;
	Person p3 ("Roger", "Alex");
	print (cout, p3) << endl;

	return 0;
}

/*

LeBron James
LeBron James
Roger Alex
请按任意键继续. . .

*/
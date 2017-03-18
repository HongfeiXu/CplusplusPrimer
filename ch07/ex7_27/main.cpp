#include "ex7_27.h"
#include <iostream>
using std::cout;

int main ()
{
	Screen myScreen (5, 5, 'X');
	myScreen.move (4, 0).set ('#').display (cout);
	cout << "\n";
	myScreen.display (cout);
	cout << "\n";

	return 0;
}

/*

XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
请按任意键继续. . .

*/
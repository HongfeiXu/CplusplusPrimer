#include <vector>
#include "Ch16_Templates_and_Generic_Programming/DebugDelete.h"

using namespace std;


class NoDefault {
	NoDefault() = delete;
};

int main()
{
	vector<NoDefault> vt;

	return 0;
}
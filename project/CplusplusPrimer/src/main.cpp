#include <iostream>
#include <type_traits>
using namespace std;

struct B1 { static int a; };
struct B2 { int a; };

struct D3 : B1, B2 { static int d; };

int main() {
    cout << is_standard_layout<D3>::value << endl;


    return 0;
}

/*

*/

#include "HasPtr.h"
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    HasPtr hp1("Lebron", 1);
    HasPtr hp2("Kobe", 10);
    HasPtr hp3("Jordan", 2);
    
    vector<HasPtr> cont { hp1, hp2, hp3 };
    
    for_each(cont.begin(), cont.end(), [](HasPtr& hp) { hp.Print(); });
    sort(cont.begin(), cont.end());
    for_each(cont.begin(), cont.end(), [](HasPtr& hp) { hp.Print(); });

    return 0;
}
/*

HasPtr::CopyConstructor
HasPtr::CopyConstructor
HasPtr::CopyConstructor
HasPtr::CopyConstructor
HasPtr::CopyConstructor
HasPtr::CopyConstructor
1 Lebron
10 Kobe
2 Jordan
HasPtr::CopyConstructor
HasPtr::CopyConstructor
HasPtr::swap()
HasPtr::CopyConstructor
HasPtr::CopyConstructor
HasPtr::swap()
HasPtr::CopyConstructor
HasPtr::swap()
1 Lebron
2 Jordan
10 Kobe
请按任意键继续. . .

*/
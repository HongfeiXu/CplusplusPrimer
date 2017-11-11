#include <iostream>
#include <string>
#include "ex12_19.h"

using namespace std;

int main()
{
    StrBlob strBlob_1({ "hello", "world", "wow" });
    StrBlobPtr p1(strBlob_1);
    cout << "strBlob_1:" << endl;
    cout << p1.deref() << endl;
    p1.incr();
    cout << p1.deref() << endl;
    p1.incr();
    cout << p1.deref() << endl;

    StrBlob strBlob_2(strBlob_1);       // 类值版本

    strBlob_1.push_back("Witcher");
    StrBlobPtr p3(strBlob_1);
    cout << "After push_back, strBlob_1:" << endl;
    cout << p3.deref() << endl;
    p3.incr();
    cout << p3.deref() << endl;
    p3.incr();
    cout << p3.deref() << endl;
    p3.incr();
    cout << p3.deref() << endl;

    StrBlobPtr p2(strBlob_2);
    cout << "strBlob_2:" << endl;
    cout << p2.deref() << endl;
    p2.incr();
    cout << p2.deref() << endl;
    p2.incr();
    cout << p2.deref() << endl;
    p2.incr();
    try
    {
        cout << p2.deref() << endl;

    }
    catch (const std::exception& e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }
    return 0;
}
/*

strBlob_1:
hello
world
wow
After push_back, strBlob_1:
hello
world
wow
Witcher
strBlob_2:
hello
world
wow
ERROR: dereference past end
请按任意键继续. . .

*/

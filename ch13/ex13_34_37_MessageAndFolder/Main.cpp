#include "Message.h"

#include <iostream>

using namespace std;

int main()
{
    Message msg1("Hello");
    Message msg2("World");

    Folder folder1;
    Folder folder2;
    Folder folder3;

    msg1.save(folder1);
    msg1.save(folder2);

    msg2.save(folder2);
    msg2.save(folder3);

    cout << "folder2: " << endl;
    folder2.debugPrint();

    Message msg3(msg1);

    cout << "folder2: " << endl;
    folder2.debugPrint();

    return 0;
}

/*

folder2:
World
Hello
folder2:
Hello
World
Hello
请按任意键继续. . .

*/
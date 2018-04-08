#include <iostream>
#include <vector>
#include <utility>
#include "Message.h"

using namespace std;

int main()
{
	Message message("hello");
	Message message2("world");

	Folder f0;
	Folder f1;

	message.save(f0);
	message2.save(f1);

	f0.debugPrint();
	f1.debugPrint();

	Message message3 = std::move(message);
	f0.debugPrint();

	return 0;
}

/*

hello
world
Message::MoveConstructor
hello
请按任意键继续. . .

*/
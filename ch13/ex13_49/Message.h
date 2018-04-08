#pragma once

#include <string>
#include <set>
#include <iostream>
#include <utility>

using namespace std;

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message& lhs, Message& rhs);
private:
    string contents;
    set<Folder*> folders;

private:
    void add_to_Folders(const Message& msg);
    void remove_from_Folders();
    void addFolder(Folder* f);
    void remFolder(Folder* f);

	//移动 folders 并更新 Folder 指针（移动构造函数和移动赋值运算符调用之）
	void move_Folders(Message *m);

public:
    explicit Message(const string& str = "") : contents(str) { }
    Message(const Message& m);
	Message(Message &&m);		// 移动构造函数
    Message& operator= (const Message&rhs);
	Message& operator= (Message &&rhs);	// 移动赋值运算符
    ~Message();
    void save(Folder& f);
    void remove(Folder& f);

    void debugPrint()
    {
        cout << contents << endl;
    }
};

void swap(Message& lhs, Message& rhs);

class Folder {
    friend class Message;
    friend void swap(Folder& lhs, Folder& rhs);
private:
    set<Message*> messages;

private:
    void add_to_Messages(const Folder& f);
    void rem_from_Messages();
    void addMsg(Message *msg);
    void remMsg(Message *msg);

public:
    Folder() = default;
    Folder(const Folder& rhs);
    Folder& operator= (const Folder& rhs);
    ~Folder();

    void debugPrint()
    {
        for (auto msg : messages)
            msg->debugPrint();
    }
};

void swap(Folder& lhs, Folder& rhs);

/*

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


hello
world
Message::MoveConstructor
hello
请按任意键继续. . .

*/


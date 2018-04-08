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

	//�ƶ� folders ������ Folder ָ�루�ƶ����캯�����ƶ���ֵ���������֮��
	void move_Folders(Message *m);

public:
    explicit Message(const string& str = "") : contents(str) { }
    Message(const Message& m);
	Message(Message &&m);		// �ƶ����캯��
    Message& operator= (const Message&rhs);
	Message& operator= (Message &&rhs);	// �ƶ���ֵ�����
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
�밴���������. . .

*/


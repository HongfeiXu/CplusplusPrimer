#pragma once

#include <string>
#include <set>
#include <iostream>

using namespace std;

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

public:
    explicit Message(const string& str = "") : contents(str) { }
    Message(const Message& rhs);
    Message& operator= (const Message&rhs);
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

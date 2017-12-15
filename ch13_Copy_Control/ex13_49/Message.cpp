#include "Message.h"

//////////////////////////////////////////////////////////////////////////
// Message Implementation

void Message::add_to_Folders(const Message& msg)
{
    for (auto f : msg.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

Message::Message(const Message& m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message::Message(Message &&m) : contents(std::move(m.contents))
{
	std::cout << "Message::MoveConstructor" << std::endl;
	move_Folders(&m);		// 移动 folders 并更新 Folder 指针
}

Message& Message::operator=(Message &&rhs)
{
	if (this != &rhs)		// 直接检查自身赋值情况
	{
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::addFolder(Folder* f)
{
    folders.insert(f);
}

void Message::remFolder(Folder* f)
{
    folders.erase(f);
}

void Message::move_Folders(Message *m)
{
	folders = std::move(m->folders);
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();		// 确保销毁 m 是无害的
}

Message& Message::operator=(const Message&rhs)
{
    // 通过先删除指针再插入它们来处理自赋值情况
    remove_from_Folders();      // 更新已有 Folder
    contents = rhs.contents;    // 从 rhs 拷贝消息内容
    folders = rhs.folders;      // 从 rhs 拷贝 Folder 指针
    add_to_Folders(rhs);        // 将本 Message 添加到那些 Folder 中
    return *this;
}

void swap(Message& lhs, Message& rhs)
{
    using std::swap;
    // 将每个消息的指针从它（原来）所在 Folder 中删除
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    swap(lhs.contents, rhs.contents);       // string swap
    swap(lhs.folders, rhs.folders);         // set swap

                                            // 将每个消息的指针调价到它（新）的 Folder 中
    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

//////////////////////////////////////////////////////////////////////////
// Folder implementation

void Folder::add_to_Messages(const Folder& f)
{
    for (auto msg : f.messages)
        msg->addFolder(this);
}

void Folder::rem_from_Messages()
{
    for (auto msg : messages)
        msg->remFolder(this);
}

Folder::Folder(const Folder& rhs) : messages(rhs.messages)
{
    add_to_Messages(rhs);
}

Folder::~Folder()
{
    rem_from_Messages();
}

void Folder::addMsg(Message *msg)
{
    messages.insert(msg);
}

void Folder::remMsg(Message *msg)
{
    messages.erase(msg);
}

Folder& Folder::operator=(const Folder& rhs)
{
    rem_from_Messages();
    messages = rhs.messages;
    add_to_Messages(rhs);
    return *this;
}

void swap(Folder& lhs, Folder& rhs)
{
    using std::swap;
    lhs.rem_from_Messages();
    rhs.rem_from_Messages();
    swap(lhs.messages, rhs.messages);
    lhs.add_to_Messages(lhs);
    rhs.add_to_Messages(rhs);
}
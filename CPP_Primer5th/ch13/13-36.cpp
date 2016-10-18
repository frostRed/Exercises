#include "13-36.h"

void Message::addFld(Folder *f) {
    folders.insert(f);
}
void Message::remFld(Folder *f) {
    folders.erase(f);
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}
//////////////////////////
void Message::add_to_Folders(const Message &m) {
    for (auto f: m.folders) {
        f->addMsg(this);
    }
}
Message::Message(const Message &m): contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}
void Message::remove_from_Folders() {
    for (auto f: folders) {
        f->remMsg(this);
    }
}
Message::~Message() {
    remove_from_Folders();
}
Message& Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}
/////////////////////////

void Folder::add_to_Messages(const Folder &f) {
    for (auto i: f.messages) {
        i->addFld(this);
    }
}
Folder::Folder(const Folder &f) :messages(f.messages) {
    add_to_Messages(f);
}
void Folder::remove_from_Messages() {
    for (auto i: messages) {
        i->remFld(this);
    }
}
Folder::~Folder() {
    remove_from_Messages();
}
Folder &Folder::operator=(const Folder &rhs) {
    remove_from_Messages();
    messages = rhs.messages;
    add_to_Messages(rhs);
    return *this;
}

void swap(Folder &lhs, Folder &rhs) {
    using std::swap;
    for (auto i: lhs.messages) {
        i->remFld(&lhs);
    }
    for (auto i: rhs.messages) {
        i->remFld(&rhs);
    }
    swap(lhs.messages, rhs.messages);
    for (auto i: lhs.messages) {
        i->addFld(&lhs);
    }
    for (auto i: rhs.messages) {
        i->addFld(&rhs);
    }
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (auto f: lhs.folders) {
        f->remMsg(&lhs);
    }
    for (auto f: rhs.folders) {
        f->remMsg(&rhs);
    }

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, lhs.contents);

    for (auto f: lhs.folders) {
        f->addMsg(&lhs);
    }
    for (auto f: rhs.folders) {
        f->addMsg(&rhs);
    }
}

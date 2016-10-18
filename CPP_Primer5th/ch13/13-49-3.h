#include <string>
#include <set>

using std::string;
using std::set;

class Folder;
class Message {
    friend class Folder;
    friend void swap(Message &, Message &);
public:
    explicit Message(const string &str = ""): contents(str) {}

    Message(const Message &);
    Message(Message &&);
    Message &operator=(const Message &);
    Message &operator=(Message &&);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

    void addFld(Folder *);
    void remFld(Folder *);

private:
    string contents;
    set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void move_Folders(Message *);
};

class Folder {
    friend Message;
    friend void swap(Folder &, Folder &);

public:
    Folder() = default;

    Folder(const Folder &);
    Folder& operator=(const Folder &);
    ~Folder();

    void addMsg(Message *);
    void remMsg(Message *);

private:
    set<Message *> messages;

    void add_to_Messages(const Folder&);
    void remove_from_Messages();
};

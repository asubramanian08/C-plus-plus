#include <memory>
using namespace std;
#include "../AB.hpp"

//contains '*' for added of modified parts
class my_list
{
private:
    struct node
    {
        A obj;
        shared_ptr<node> next;
        weak_ptr<node> prev; //*
        node(const A &obj, const shared_ptr<node> &next = nullptr, const shared_ptr<node> &prev = nullptr)
            : obj(obj), next(next), prev(prev) {} //* added prev into constructor
    };
    shared_ptr<node> head;

public:
    my_list() : head(nullptr) {}
    void AddFront(A item)
    {
        head = make_shared<node>(item, head);
        if (head->next != nullptr)   //*
            head->next->prev = head; //*
    }
    void Clear() { head = nullptr; }
};

int main(void)
{
    my_list test;
    test.AddFront(A(-1));
    test.AddFront(A(1));
    test.AddFront(A());
    test.Clear();
    return 0;
}
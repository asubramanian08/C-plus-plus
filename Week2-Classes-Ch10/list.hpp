template <typename Item>
class List
{
private:
    Item *arr;
    int nItems;
    int max_sz;

public:
    List(int max_size = 100);
    void push(Item &element);
    bool isEmpty(void) const;
    bool isFull(void) const;
    void visit(void (*action)(Item &));
    ~List(void);
};
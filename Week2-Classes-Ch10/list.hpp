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

template <typename Item>
List<Item>::List(int max_size)
{
    int max_sz = max_size;
    arr = new Item[max_size];
    nItems = 0;
}
template <typename Item>
void List<Item>::push(Item &element)
{
    if (nItems == max_sz)
        return;
    arr[nItems] = element;
    nItems++;
}
template <typename Item>
bool List<Item>::isEmpty(void) const
{
    return nItems == 0;
}
template <typename Item>
bool List<Item>::isFull(void) const
{
    return nItems == max_sz;
}
template <typename Item>
void List<Item>::visit(void (*action)(Item &))
{
    for (int i = 0; i < nItems; i++)
        action(arr[i]);
}
template <typename Item>
List<Item>::~List()
{
    delete[] arr;
}
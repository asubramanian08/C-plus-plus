#include "list.hpp"
//List<typename Item>::List(int max_size)
template <class Item>
List<Item>::List(int max_size)
{
    int max_sz = max_size;
    arr = new Item[max_size];
    nItems = 0;
}
//void List<typename Item>::push(Item &element)
template <class Item>
void List<Item>::push(Item &element)
{
    if (nItems == max_sz)
        return;
    arr[nItems] = element;
    nItems++;
}
//bool List<typename Item>::isEmpty(void) const
template <class Item>
bool List<Item>::isEmpty(void) const
{
    return nItems == 0;
}
//bool List<typename Item>::isFull(void) const
template <class Item>
bool List<Item>::isFull(void) const
{
    return nItems == max_sz;
}
//void List<typename Item>::visit(void (*action)(Item &))
template <class Item>
void List<Item>::visit(void (*action)(Item &))
{
    for (int i = 0; i < nItems; i++)
        action(arr[i]);
}
//List<typename Item>::~List(void)
template <class Item>
List<Item>::~List()
{
    delete[] arr;
}
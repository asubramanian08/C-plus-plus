#include <stdexcept>
using namespace std;
#include "SplayMap.hpp"

#pragma region "HELPERS"

struct SplayMap::Node
{
    Node *next[2], *par;
    pair<int, int> key_value;
    Node(const int &k, const int &v) : key_value(k, v), par(nullptr) { next[0] = next[1] = nullptr; }
};

SplayMap::Node *SplayMap::splay(Node *subtree, const int &key) const
{
    // setup and check
    bool side;
    if (subtree == nullptr || key == subtree->key_value.first ||
        subtree->next[side = (key > subtree->key_value.first)] == nullptr)
        return subtree;
    // splay and rotate
    Node *ret = splay(subtree->next[side], key);
    subtree->next[side] = ret->next[!side];
    if (ret->next[!side] != nullptr)
        ret->next[!side]->par = subtree;
    ret->next[!side] = subtree;
    subtree->par = ret;
    return ret;
}

SplayMap::Node *SplayMap::splay(const int &key)
{
    root = splay(root, key);
    if (root != nullptr)
        root->par = nullptr;
    return root;
}

void SplayMap::deleteMap(Node *subtree) const
{
    if (subtree == nullptr)
        return;
    deleteMap(subtree->next[0]);
    deleteMap(subtree->next[1]);
    delete subtree;
}

size_t SplayMap::size(Node *subtree) const { return subtree == nullptr ? 0 : (1 + size(subtree->next[0]) + size(subtree->next[1])); }

#pragma endregion

#pragma region "MEMBER FUNCTIONS"

#pragma endregion

#pragma region "ITERATORS"

SplayMap::Iterator::reference SplayMap::Iterator::operator*() const { return ptr->key_value; }
SplayMap::Iterator::pointer SplayMap::Iterator::operator->() { return &ptr->key_value; }
SplayMap::Iterator &SplayMap::Iterator::operator++()
{
    if (ptr == nullptr)
        return *this;
    if (ptr->next[1] != nullptr)
    {
        ptr = ptr->next[1];
        while (ptr->next[0] != nullptr)
            ptr = ptr->next[0];
        return *this;
    }
    int orgKey = ptr->key_value.first;
    while (ptr != nullptr && ptr->key_value.first <= orgKey)
        ptr = ptr->par;
    return *this;
}
SplayMap::Iterator SplayMap::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}
bool operator==(const SplayMap::Iterator &i1, const SplayMap::Iterator &i2) { return i1.ptr == i2.ptr; };
bool operator!=(const SplayMap::Iterator &i1, const SplayMap::Iterator &i2) { return i1.ptr != i2.ptr; };

SplayMap::Iterator SplayMap::begin() const
{
    if (empty())
        return end();
    Node *curr = root;
    while (curr->next[0] != nullptr)
        curr = curr->next[0];
    return Iterator(curr);
}

SplayMap::Iterator SplayMap::end() const { return Iterator(nullptr); }

#pragma endregion

#pragma region "CAPACITY"

bool SplayMap::empty(void) const { return root == nullptr; }

size_t SplayMap::size(void) const { return size(root); }

#pragma endregion

#pragma region "ELEMENT ACCESS"

int &SplayMap::operator[](const int &key) { return insert(key, int())->second; }

int &SplayMap::at(const int &key) { return contains(key) ? root->key_value.second : throw std::out_of_range("SplayMap::at(const int& key): No instance of key"); }

#pragma endregion

#pragma region "MODIFIERS"

SplayMap::Iterator SplayMap::insert(const int &key, const int &value)
{
    Node *temp = new Node(key, value);
    if (empty())
    {
        root = temp;
        return Iterator(root);
    }
    // Binary Tree insert
    Node *search = root;
    while (key != search->key_value.first &&
           search->next[key > search->key_value.first] != nullptr)
        search = search->next[key > search->key_value.first];
    if (key == search->key_value.first)
    { // already exists
        delete temp;
        temp = search;
    }
    else // create
    {
        search->next[key > search->key_value.first] = temp;
        temp->par = search;
    }
    splay(key);
    return Iterator(root);
}

size_t SplayMap::erase(const int &key)
{
    if (!contains(key))
        return 0;
    Node *subLeft = root->next[0], *subRight = root->next[1];
    delete root;
    if ((root = subLeft) != nullptr)
        root->par = nullptr;
    else // no left subtree
    {
        if ((root = subRight) != nullptr)
            root->par = nullptr;
        return 1;
    }
    Node *curr = root;
    while (curr->next[1] != nullptr)
        curr = curr->next[1];
    splay(curr->key_value.first)->next[1] = subRight;
    if (subRight != nullptr)
        subRight->par = root;
    return 1;
}

void SplayMap::clear(void) { deleteMap(root), root = nullptr; }

#pragma endregion

#pragma region "OPERATIONS"

SplayMap::Iterator SplayMap::find(const int &key)
{
    Iterator ret(root = splay(key));
    if (ret != end() && ret->first == key)
        return ret;
    else
        return end();
}

SplayMap::Iterator SplayMap::lower_bound(const int &key)
{
    Iterator ret(root = splay(key));
    while (ret != end() && ret->first < key)
        ret++;
    return ret;
}

SplayMap::Iterator SplayMap::upper_bound(const int &key)
{
    Iterator ret(root = splay(key));
    while (ret != end() && ret->first <= key)
        ret++;
    return ret;
}

bool SplayMap::contains(const int &key) { return find(key) != end(); }

#pragma endregion
#include <stdexcept>
using namespace std;
#include "SplayMap.hpp"

#pragma region "HELPERS"

SplayMap::Node::Node(const int &k, const int &v) : key_value(k, v), par(nullptr) { next[0] = next[1] = nullptr; }

SplayMap::Node *SplayMap::BTSearch(const int &key) const
{
    Node *search = root;
    if (search == nullptr) return search;
    while (key != search->key_value.first &&
           search->next[key > search->key_value.first] != nullptr)
        search = search->next[key > search->key_value.first];
    return search;
}

SplayMap::Node *SplayMap::splay(Node *subtree, const int &key)
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
    return subtree->par = ret;
}

SplayMap::Node *SplayMap::splay(const int &key)
{
    root = splay(root, key);
    if (root != nullptr)
        root->par = nullptr;
    return root;
}

void SplayMap::recursiveDelete(Node *subtree)
{
    if (subtree == nullptr) return;
    recursiveDelete(subtree->next[0]);
    recursiveDelete(subtree->next[1]);
    delete subtree; elementCt--;
}

#pragma endregion

#pragma region "MEMBER FUNCTIONS"

#pragma endregion

#pragma region "ITERATORS"

SplayMap::iterator::reference SplayMap::iterator::operator*() const { return ptr->key_value; }
SplayMap::iterator::pointer SplayMap::iterator::operator->() const { return &ptr->key_value; }
SplayMap::iterator &SplayMap::iterator::operator++()
{
    if (ptr == nullptr) return *this;
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
SplayMap::iterator SplayMap::iterator::operator++(int) { iterator temp = *this; ++(*this); return temp; }
bool operator==(const SplayMap::iterator &i1, const SplayMap::iterator &i2) { return i1.ptr == i2.ptr; }
bool operator!=(const SplayMap::iterator &i1, const SplayMap::iterator &i2) { return i1.ptr != i2.ptr; }

SplayMap::iterator SplayMap::begin()
{
    if (empty()) return end();
    Node *search = root;
    while (search->next[0] != nullptr)
        search = search->next[0];
    return iterator(search);
}

SplayMap::iterator SplayMap::end() { return iterator(nullptr); }

#pragma endregion

#pragma region "CAPACITY"

bool SplayMap::empty(void) const { return root == nullptr; }

size_t SplayMap::size(void) const { return elementCt; }

#pragma endregion

#pragma region "ELEMENT ACCESS"

int &SplayMap::operator[](const int &key) { return insert(key, int())->second; }

const int &SplayMap::operator[](const int &key) const { return at(key); }

int &SplayMap::at(const int &key) { return contains(key) ? root->key_value.second : throw std::out_of_range("SplayMap::at(const int& key): No instance of key"); }

const int &SplayMap::at(const int &key) const { return contains(key) ? BTSearch(key)->key_value.second : throw std::out_of_range("SplayMap::at(const int& key): No instance of key"); }

#pragma endregion

#pragma region "MODIFIERS"

SplayMap::iterator SplayMap::insert(const int &key, const int &value)
{
    Node *temp = new Node(key, value); elementCt++;
    if (empty()) { root = temp; return iterator(root); }
    Node *search = BTSearch(key);
    if (key == search->key_value.first) { delete temp; elementCt--; temp = search; } // already exists
    else { search->next[key > search->key_value.first] = temp; temp->par = search; } // create
    return iterator(splay(key));
}

size_t SplayMap::erase(const int &key)
{
    if (!contains(key)) return 0;
    Node *subLeft = root->next[0], *subRight = root->next[1];
    delete root; elementCt--;
    if ((root = subLeft) != nullptr)
        root->par = nullptr;
    else // no left subtree
    {
        if ((root = subRight) != nullptr)
            root->par = nullptr;
        return 1;
    }
    Node *search = BTSearch(key); // largest
    splay(search->key_value.first)->next[1] = subRight;
    if (subRight != nullptr)
        subRight->par = root;
    return 1;
}

void SplayMap::clear(void) { recursiveDelete(root); root = nullptr; }

#pragma endregion

#pragma region "OPERATIONS"

SplayMap::iterator SplayMap::find(const int &key)
{
    iterator ret(root = splay(key));
    return (ret != end() && ret->first == key) ? ret : end();
}

SplayMap::iterator SplayMap::lower_bound(const int &key)
{
    iterator ret(root = splay(key));
    while (ret != end() && ret->first < key) ret++;
    return ret;
}

SplayMap::iterator SplayMap::upper_bound(const int &key)
{
    iterator ret(root = splay(key));
    while (ret != end() && ret->first <= key) ret++;
    return ret;
}

bool SplayMap::contains(const int &key) { return find(key) != end(); }

bool SplayMap::contains(const int &key) const { return !empty() && BTSearch(key)->key_value.first == key; }

#pragma endregion
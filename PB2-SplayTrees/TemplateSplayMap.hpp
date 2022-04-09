#include <iterator>
#include <stdexcept>

template <typename K, typename V>
class TmpSplayMap
{
private:
#pragma region "HELPERS"
    size_t elementCt;
    struct Node
    {
        Node *next[2], *par; std::pair<K, V> key_value;
        Node(const K &k, const V &v) : key_value(k, v), par(nullptr) { next[0] = next[1] = nullptr; }
    } * root;
    Node *BTSearch(const K &key) const
    {
        Node *search = root;
        if (search == nullptr) return search;
        while (key != search->key_value.first &&
               search->next[key > search->key_value.first] != nullptr)
            search = search->next[key > search->key_value.first];
        return search;
    }
    Node *splay(Node *subtree, const K &key)
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
    Node *splay(const K &key)
    {
        root = splay(root, key);
        if (root != nullptr)
            root->par = nullptr;
        return root;
    }
    void recursiveDelete(Node *subtree)
    {
        if (subtree == nullptr) return;
        recursiveDelete(subtree->next[0]);
        recursiveDelete(subtree->next[1]);
        delete subtree; elementCt--;
    }
#pragma endregion

public:
#pragma region "MEMBER FUNCTIONS"
    TmpSplayMap(void) { root = nullptr; elementCt = 0; }
    ~TmpSplayMap(void) { clear(); }
    TmpSplayMap(const TmpSplayMap &) = delete;
    TmpSplayMap &operator=(TmpSplayMap &) = delete;
#pragma endregion

#pragma region "ITERATORS"
    template <typename I>
    class Iterator final
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = I;
        using pointer = value_type *;
        using reference = value_type &;

    public:
        reference operator*() const { return ptr->key_value; }
        pointer operator->() const { return &ptr->key_value; }
        Iterator<I> &operator++() /* Prefix */
        {
            if (ptr == nullptr) return *this;
            if (ptr->next[1] != nullptr)
            {
                ptr = ptr->next[1];
                while (ptr->next[0] != nullptr)
                    ptr = ptr->next[0];
                return *this;
            }
            K orgKey = ptr->key_value.first;
            while (ptr != nullptr && ptr->key_value.first <= orgKey)
                ptr = ptr->par;
            return *this;
        }
        Iterator<I> operator++(int) /* Postfix */ { Iterator<I> temp = *this; ++(*this); return temp; }
        friend bool operator==(const Iterator<I> &i1, const Iterator<I> &i2) { return i1.ptr == i2.ptr; }
        friend bool operator!=(const Iterator<I> &i1, const Iterator<I> &i2) { return i1.ptr != i2.ptr; }
        friend class TmpSplayMap;

    private:
        Node *ptr;
        Iterator<I>(Node *p) : ptr(p){};
    };
    using iterator = Iterator<std::pair<K, V>>;
    using const_iterator = Iterator<const std::pair<K, V>>;
    iterator begin()
    {
        if (empty()) return end();
        Node *search = root;
        while (search->next[0] != nullptr)
            search = search->next[0];
        return iterator(search);
    }
    const_iterator begin() const
    {
        if (empty()) return cend();
        Node *search = root;
        while (search->next[0] != nullptr)
            search = search->next[0];
        return const_iterator(search);
    }
    const_iterator cbegin() const { return begin(); }
    iterator end() { return iterator(nullptr); }
    const_iterator end() const { return const_iterator(nullptr); }
    const_iterator cend() const { return end(); }
#pragma endregion

#pragma region "CAPACITY"
    bool empty(void) const { return root == nullptr; }
    size_t size(void) const { return elementCt; }
#pragma endregion

#pragma region "ELEMENT ACCESS"
    V &operator[](const K &key) { return insert(key, V())->second; }
    const V &operator[](const K &key) const { return at(key); }
    V &at(const K &key) { return contains(key) ? root->key_value.second : throw std::out_of_range("TmpSplayMap<K, V>::at(const V& key): No instance of key"); }
    const V &at(const K &key) const { return contains(key) ? find(key)->second : throw std::out_of_range("TmpSplayMap<K, V>::at(const V& key) const: No instance of key"); }
#pragma endregion

#pragma region "MODIFIERS"
    iterator insert(const K &key, const V &value)
    {
        Node *temp = new Node(key, value); elementCt++;
        if (empty()) { root = temp; return iterator(root); }
        Node *search = BTSearch(key);
        if (key == search->key_value.first) { delete temp; elementCt--; temp = search; } // already exists
        else { search->next[key > search->key_value.first] = temp; temp->par = search; } // create
        return iterator(splay(key));
    }
    size_t erase(const K &key)
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
        if (subRight != nullptr) subRight->par = root;
        return 1;
    }
    void clear(void) { recursiveDelete(root); root = nullptr; }
#pragma endregion

#pragma region "OPERATIONS"
    iterator find(const K &key)
    {
        iterator ret(root = splay(key));
        return (ret != end() && ret->first == key) ? ret : end();
    }
    const_iterator find(const K &key) const
    {
        const_iterator ret(BTSearch(key));
        return (ret != cend() && ret->first == key) ? ret : cend();
    }
    iterator lower_bound(const K &key)
    {
        iterator ret(root = splay(key));
        while (ret != end() && ret->first < key) ret++;
        return ret;
    }
    const_iterator lower_bound(const K &key) const
    {
        const_iterator ret(BTSearch(key));
        while (ret != cend() && ret->first < key) ret++;
        return ret;
    }
    iterator upper_bound(const K &key)
    {
        iterator ret(root = splay(key));
        while (ret != end() && ret->first <= key) ret++;
        return ret;
    }
    const_iterator upper_bound(const K &key) const
    {
        const_iterator ret(BTSearch(key));
        while (ret != cend() && ret->first <= key) ret++;
        return ret;
    }
    bool contains(const K &key) { return find(key) != end(); }
    bool contains(const K &key) const { return find(key) != cend(); }
#pragma endregion
};
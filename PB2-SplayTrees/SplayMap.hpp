#include <iterator>

class SplayMap
{
private:
#pragma region "HELPERS"
    size_t elementCt;
    struct Node
    {
        Node *next[2], *par;
        std::pair<int, int> key_value;
        Node(const int &k, const int &v);
    } * root;
    Node *BTSearch(const int &key) const;
    Node *splay(Node *subtree, const int &key);
    Node *splay(const int &key);
    void recursiveDelete(Node *subtree);
#pragma endregion

public:
#pragma region "MEMBER FUNCTIONS"
    SplayMap(void) { root = nullptr; elementCt = 0; }
    ~SplayMap(void) { clear(); }
    SplayMap(const SplayMap &) = delete;
    SplayMap &operator=(SplayMap &) = delete;
#pragma endregion

#pragma region "ITERATORS"
    class iterator final
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = std::pair<int, int>;
        using pointer = value_type *;
        using reference = value_type &;

    public:
        reference operator*() const;
        pointer operator->() const;
        iterator &operator++();   // Prefix
        iterator operator++(int); // Postfix
        friend bool operator==(const iterator &i1, const iterator &i2);
        friend bool operator!=(const iterator &i1, const iterator &i2);
        friend class SplayMap;

    private:
        Node *ptr;
        iterator(Node *p) : ptr(p){};
    };
    iterator begin();
    iterator end();
#pragma endregion

#pragma region "CAPACITY"
    bool empty(void) const;
    size_t size(void) const;
#pragma endregion

#pragma region "ELEMENT ACCESS"
    int &operator[](const int &key);
    const int &operator[](const int &key) const;
    int &at(const int &key);
    const int &at(const int &key) const;
#pragma endregion

#pragma region "MODIFIERS"
    iterator insert(const int &key, const int &value);
    size_t erase(const int &key);
    void clear(void);
#pragma endregion

#pragma region "OPERATIONS"
    iterator find(const int &key);
    iterator lower_bound(const int &key);
    iterator upper_bound(const int &key);
    bool contains(const int &key);
    bool contains(const int &key) const;
#pragma endregion
};
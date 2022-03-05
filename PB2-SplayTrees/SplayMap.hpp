#include <iterator>

/**test which a separate driver - compare with map
 * map a map with 50 million values
 * use a vector of 500 values and find them over and over
 * Time this for both map and SplayMap */
// Make SplayMap a template

class SplayMap
{
private:
#pragma region "HELPERS"
    struct Node;
    Node *root;
    Node *splay(Node *subtree, const int &key) const;
    Node *splay(const int &key);
    void deleteMap(Node *subtree) const;
    size_t size(Node *subtree) const;
#pragma endregion

public:
#pragma region "MEMBER FUNCTIONS"
    SplayMap(void)
    {
        root = nullptr;
    }
    ~SplayMap(void) { deleteMap(root); }
    SplayMap(const SplayMap &) = delete;
    SplayMap &operator=(SplayMap &) = delete;
#pragma endregion

#pragma region "ITERATORS"
    class Iterator final
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = std::pair<int, int>;
        using pointer = value_type *;
        using reference = value_type &;

    public:
        reference operator*() const;
        pointer operator->();
        Iterator &operator++();   // Prefix
        Iterator operator++(int); // Postfix
        friend bool operator==(const Iterator &i1, const Iterator &i2);
        friend bool operator!=(const Iterator &i1, const Iterator &i2);
        friend class SplayMap;

    private:
        Node *ptr;
        Iterator(Node *p) : ptr(p){};
    };
    Iterator begin() const;
    Iterator end() const;
#pragma endregion

#pragma region "CAPACITY"
    bool empty(void) const;
    size_t size(void) const; // O(N) complexity
#pragma endregion

#pragma region "ELEMENT ACCESS"
    int &operator[](const int &key);
    int &at(const int &key);
#pragma endregion

#pragma region "MODIFIERS"
    Iterator insert(const int &key, const int &value); // lazy insert
    size_t erase(const int &key);
    void clear(void);
#pragma endregion

#pragma region "OPERATIONS"
    Iterator find(const int &key);
    Iterator lower_bound(const int &key);
    Iterator upper_bound(const int &key);
    bool contains(const int &key);
#pragma endregion
};
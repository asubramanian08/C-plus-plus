#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
// originally made in Maps TE5 -> function prototype given
// modified (bucket contents) in Maps TE7
// modified (for the worst chain) in Sets TE5 (and var name)
template <typename T, typename P>
void bucket_stats(T &unordered, P value = getVal<T>())
{
    using std::cout;
    using std::endl;
    cout << "Bucket Stats:" << endl
         << "Size: " << unordered.size() << endl
         << "Number of buckets: " << unordered.bucket_count() << endl
         << "Load Factor: " << unordered.load_factor() << endl
         << "Max load factor: " << unordered.max_load_factor() << endl
         << "All bucket's contents:" << endl;
    size_t maxChain = 0;
    for (int i = 0; i < unordered.bucket_count(); i++)
    {
        cout << "Bucket " << i << ':';
        for (auto buck_it = unordered.begin(i); buck_it != unordered.end(i); buck_it++)
            cout << ' ' << value(*buck_it);
        cout << endl;
        maxChain = max(maxChain, static_cast<size_t>(distance(unordered.begin(i), unordered.end(i))));
    }
    cout << "The maximum chain is: " << maxChain << endl
         << endl;
}

template <typename T>
auto getVal(const T &item)
{
    return item;
}

template <typename T1, typename T2>
auto geteVal(const std::pair<T1, T2> &item)
{
    return item.second;
}
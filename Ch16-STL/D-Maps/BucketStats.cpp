#include <iostream>
// originally made in Maps TE5 -> function prototype given
// modified (bucket contents) in Maps TE7
template <typename T>
void bucket_stats(T &umap)
{
    using std::cout;
    using std::endl;
    cout << "Bucket Stats:" << endl
         << "Size: " << umap.size() << endl
         << "Number of buckets: " << umap.bucket_count() << endl
         << "Load Factor: " << umap.load_factor() << endl
         << "Max load factor: " << umap.max_load_factor() << endl
         << "All bucket's contents:" << endl;
    for (int i = 0; i < umap.bucket_count(); i++)
    {
        cout << "Bucket " << i << ':';
        for (auto buck_it = umap.begin(i); buck_it != umap.end(i); buck_it++)
            cout << ' ' << buck_it->second;
        cout << endl;
    }
    cout << endl;
}
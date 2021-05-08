#include <unordered_map>
#include <iostream>
using namespace std;

//from TE5
template <typename T>
void bucket_stats(T &umap)
{
    cout << "Bucket Stats:" << endl
         << "Size: " << umap.size() << endl
         << "Number of buckets: " << umap.bucket_count() << endl
         << "Load Factor: " << umap.load_factor() << endl
         << "Max load factor: " << umap.max_load_factor() << endl
         << endl;
}

int main(void)
{
    unordered_map<int, int> umap;
    umap.max_load_factor(0.5);
    //umap.rehash(1024);
    umap.reserve(1024);
    bucket_stats(umap);

    // Rehash sets the number of buckets to what is passed
    // Reserve set the number of buckets to passed / max load factor
    return 0;
}
#include <unordered_map>
#include <iostream>
#include "../../BucketStats.cpp"
using namespace std;

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
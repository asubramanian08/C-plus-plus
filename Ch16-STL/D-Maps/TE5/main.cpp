#include <iostream>
#include <unordered_map>
#include <random>
using namespace std;

//function prototype given
//Why is this a template function
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
    //It only loops once
    unordered_map<int, int> umap;
    uniform_int_distribution<int> rand;
    int bCount;

    //first run
    bCount = umap.bucket_count();
    for (int i = 0; i <= bCount; i++)
    {
        umap.insert(make_pair(i, i));
        bucket_stats(umap);
    }

    //second fun (change max load factor)
    umap.clear();
    umap.max_load_factor(0.5);
    bCount = umap.bucket_count();
    for (int i = 0; i - 1 <= bCount; i++)
    {
        umap.insert(make_pair(i, i));
        bucket_stats(umap);
    }

    /** Answers (to the question f-h):
     * The load factor is displaying: the size/number of buckets
     * When we go over the number of buckets: ? (runs once)
     * The number of buckets increase when: the load factor 
     reaches the max load factor (runs once) */
}
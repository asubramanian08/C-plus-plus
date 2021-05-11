#include <iostream>
#include <unordered_map>
#include <random>
#include "../BucketStats.cpp"
using namespace std;

#define bucketLoop 30

int main(void)
{
    unordered_map<int, int> umap;    // 1 or default max load factor
    unordered_map<int, int> umapMLF; // 0.5 max load factor
    uniform_int_distribution<int> rand;
    int bCount;

    //first run
    cout << "Buckets with default max load factor:" << endl;
    for (int i = 0; i <= bucketLoop; i++)
    {
        umap.insert(make_pair(i, i));
        bucket_stats(umap);
    }

    //second run (change max load factor)
    cout << "Buckets with 0.5 max load factor:" << endl;
    umapMLF.max_load_factor(0.5);
    bCount = umapMLF.bucket_count();
    for (int i = 0; i <= bucketLoop; i++)
    {
        umapMLF.insert(make_pair(i, i));
        bucket_stats(umapMLF);
    }

    /** Answers (to the question f-h):
     * The load factor is displaying: the size/number of buckets
     * When we go over the number of buckets: the number of buckets resizes (2x + 1)
     * The number of buckets increase when: the load factor reaches the max load factor */
}
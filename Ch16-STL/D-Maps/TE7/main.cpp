#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class vaccine
{
private:
    string manufacturer;
    string id_version;
    int batch_number;

public:
    vaccine(const string &manu, const string &id, int batch)
        : manufacturer(manu), id_version(id), batch_number(batch) {}

    bool operator==(const vaccine &va) const
    {
        return manufacturer == va.manufacturer &&
               id_version == va.id_version &&
               batch_number == va.batch_number;
    }
    friend class vaccine_hash;
};

//shell given -> why can't I overload hast<vaccine>
struct vaccine_hash
{
    size_t operator()(const vaccine &v) const
    {
        return ((hash<string>()(v.manufacturer) >> 1) ^
                hash<string>()(v.id_version) << 1) ^
               v.batch_number << 2;
    }
};

//from TE5 -> edited
template <typename T>
void bucket_stats(T &umap)
{
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

int main(void)
{
    //some error is happening of run time
    unordered_map<vaccine, int, vaccine_hash> vac_map;
    //insert statement given
    vac_map.insert({{{"Pfizer", "23ki21", 1}, 890},
                    {{"Pfizer", "23ki21", 2}, 721},
                    {{"Pfizer", "23ki21", 3}, 652},
                    {{"Pfizer", "23ki23", 1}, 1012},
                    {{"Pfizer", "23ki23", 2}, 1618},
                    {{"Pfizer", "23ki23", 4}, 813},
                    {{"Moderna", "oq112", 40}, 900},
                    {{"Moderna", "oq112", 50}, 600},
                    {{"Moderna", "oq224", 10}, 300},
                    {{"Moderna", "oq224", 20}, 400},
                    {{"Moderna", "oq224", 80}, 800},
                    {{"Moderna", "oq330", 30}, 700}});

    bucket_stats(vac_map);
    //There are (not) collision ?
    return 0;
}
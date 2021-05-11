#include <string>
#include <unordered_map>
#include <iostream>
#include "../BucketStats.cpp"
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
    friend struct hash<vaccine>;
};

//shell given -> instead of vaccine_hash
template <>
struct hash<vaccine>
{
    size_t operator()(const vaccine &v) const
    {
        return (hash<int>()(v.batch_number) >> 1) ^
               (hash<string>()(v.id_version) << 1) ^
               hash<string>()(v.manufacturer);
    } // can use boost lib :: hash combine
};

int main(void)
{
    unordered_map<vaccine, int> vac_map; //would need to add vaccine_hash as template arg
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
    //There are some collisions
    return 0;
}
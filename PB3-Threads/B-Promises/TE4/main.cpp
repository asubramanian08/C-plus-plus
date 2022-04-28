#include <queue>
#include <memory>
using namespace std;
#define TSQ_TPL template <typename T>

// given threadsafe_queue declarations
template <typename T>
class threadsafe_queue
{
private:
    mutable mutex mut; // HELP why define as mutable
    queue<T> data_queue;

public:
    threadsafe_queue();
    void push(T new_value);
    bool try_pop(T &value);
    shared_ptr<T> try_pop(); // HELP why shared_ptr and not unique
    bool empty() const;
    auto size() const;
};

// threadsafe_queue implementations
TSQ_TPL threadsafe_queue<T>::threadsafe_queue() {}
TSQ_TPL void threadsafe_queue<T>::push(T new_value)
{
    lock_guard<mutex> g(mut);
    data_queue.push(new_value);
}
TSQ_TPL bool threadsafe_queue<T>::try_pop(T &value)
{
    lock_guard<mutex> g(mut);
    // FINISH
}
// FINISH
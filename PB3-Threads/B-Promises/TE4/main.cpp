#include <queue>
#include <memory>
#include <mutex>
using namespace std;
#define TSQ_TPL template <typename T>

// given threadsafe_queue declarations
template <typename T>
class threadsafe_queue
{
private:
    mutable mutex mut;
    queue<T> data_queue;

public:
    threadsafe_queue();
    void push(T new_value);
    bool try_pop(T &value);
    unique_ptr<T> try_pop();
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
    try
    {
        value = data_queue.front();
        data_queue.pop();
    }
    catch (...) { value = nullptr; }
    return value != nullptr;
}
TSQ_TPL unique_ptr<T> threadsafe_queue<T>::try_pop()
{
    lock_guard<mutex> g(mut);
    unique_ptr<T> up;
    try
    {
        up = make_unique(data_queue.front());
        data_queue.pop();
    }
    catch (...) { }
    return up;
}
TSQ_TPL bool threadsafe_queue<T>::empty() const
{
    lock_guard<mutex> g(mut);
    return data_queue.empty();
}
TSQ_TPL auto threadsafe_queue<T>::size() const
{
    lock_guard<mutex> g(mut);
    return data_queue.size();
}

int main(void)
{
    threadsafe_queue<int> tq;
    
    return 0;
}
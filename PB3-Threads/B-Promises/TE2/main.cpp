#include <future>
#include <thread>
#include "../../../Timer.cpp"
using namespace std;

template <typename Func>
auto packagedAsync(Func f)
{
    using Ret = typename result_of<Func()>::type;
    packaged_task<Ret()> PATask(f);
    future<Ret> PAFut = PATask.get_future();
    thread PAThread(move(PATask));
    PAThread.detach();
    return PAFut;
}

int dummyFunc()
{
    int value = 0;
    for (int i = 0; i < 1'000'000'000; i++)
        value = ((value + 1) << 7) ^ ((value - 1) >> 4);
    return value;
}

int main(void) { DisplayTime([]() { return packagedAsync(dummyFunc).get(); }, "Dummy function"); }
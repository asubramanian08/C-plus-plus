#include <chrono>
#include <fstream>
#include <string>
#include <mutex>
#include "../../A-Introduction/TE2/main.cpp"
using namespace std;

ofstream ofile; // output file stream
string filename = R"(./PB3-Threads/B-Promises/TE3/ThreadIDs.txt)";
once_flag wfFlag;
mutex wfMut;

void WriteToFile()
{
    call_once(wfFlag, []() { ofile.open(filename); });
    lock_guard<mutex> wfGuard(wfMut);
    ofile << "Thread num: " << this_thread::get_id() << endl;
}

int main(void)
{
    RunThreads(WriteToFile, 8, false);
    this_thread::sleep_for(chrono::nanoseconds(1'000'000'000));
}
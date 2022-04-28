#include <chrono>
#include <fstream>
#include <string>
#include <mutex>
#include "../../A-Intro/TE2/main.cpp"
using namespace std;

ofstream ofile; // output file stream
string filename = R"(./PB3-Threads/B-Promises/TE3/ThreadIDs.txt)";
mutex fileMut;

// HELP printing one or no threads
void WriteToFile()
{
    lock_guard<mutex> fileGuard(fileMut);
    ofile.open(filename);
    ofile << "Thread num: " << this_thread::get_id() << endl;
    ofile.close();
}

int main(void)
{
    RunThreads(WriteToFile, 8, false);
    this_thread::sleep_for(chrono::nanoseconds(1'000'000'000));
}
#include <memory>
#include <string>
using namespace std;

int main(void)
{
    unique_ptr<string> Ted = make_unique<string>(string("Ted")); //line given
    //I can use the unique_ptr release method and pass that to the shared pointer constructor
    shared_ptr<string> Ted_shared(Ted.release());
    return 0;
}
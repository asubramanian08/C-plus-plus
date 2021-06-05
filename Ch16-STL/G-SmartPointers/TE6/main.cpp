#include <memory>
using namespace std;
#include "Shape.hpp"

int main(void)
{
    //Test line given
    unique_ptr<Shape> p = MakeShape("Triangle");
    return 0;
}
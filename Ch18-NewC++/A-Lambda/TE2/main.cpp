int main(void)
{
    int x = 3;
    auto addX = [x](int y) { /*x = x + 1;*/ return x + y; };
    // the () operator is const
    // "mutable" removes the const specifier
    auto addY = [x](int y)
    {
        y--;
        return x + y;
    }; // not necessary because its not chainging the class's vars
    // NOTE: make lambda "noexept" for speed
    return 0;
}
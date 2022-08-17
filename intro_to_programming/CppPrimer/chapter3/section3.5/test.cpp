#include <iostream>
#include <iterator>
int main()
{
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *beg = std::begin(ia);
    int *last = std::end(ia);

    while (beg != last)
    {
        std::cout << *beg;
        beg++;
    }
    return 0;
}
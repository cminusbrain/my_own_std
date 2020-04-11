#include <iostream>
#include <ctime>
#include "vector.h"

int main()
{
    Vector<int> a;
    srand(std::time(0));
    for (int i = 0; i < 10; i++)
    {
        a.push_back(rand() % 10);
    }
    std::cout << a << a;
    return 0;
}

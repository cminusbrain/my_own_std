#include <iostream>
#include <ctime>
#include <vector/vector.h>

int main()
{
    Vector a;
    srand(std::time(nullptr));
    for (int i = 0; i < 10; i++)
    {
        a.push_back(rand() % 10);
    }
    std::cout << a << a;
    return 0;
}

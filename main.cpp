#include <iostream>
#include <file/file.h>

int main()
{
    File f("./test.txt");
    double a = 5.1;
    f << a;
    double b;
    f >> b;
    std::cout << b;
}

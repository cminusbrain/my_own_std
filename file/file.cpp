#include <file/file.h>


File::File(const std::string &file_path) :
    path(file_path),
    descriptor(-1)
{}

File::~File()
{

}

int File::Open()
{

}

void File::Close()
{

}

std::vector<unsigned char> File::Read(int size)
{

}

void File::Write(const std::vector<unsigned char> &data)
{

}

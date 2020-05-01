#pragma once
#include <vector>
#include <string>

class File
{
public:

    File(const std::string &file_path);

    ~File();

    int Open();

    void Close();

    std::vector<unsigned char> Read(int size);

    void Write(const std::vector<unsigned char> &data);

private:

    int descriptor;
    std::string path;

};

#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>

class File
{
public:

    File(const std::string &file_path);

    ~File();

    void Open();

    void Close();

    std::vector<uint8_t> Read(size_t size);

    void Write(const std::vector<uint8_t> &data);

private:

    int descriptor;
    std::string path;

};

template<typename T>
File &operator<<(File &f, const T &value)
{
    std::vector<uint8_t> tmp(sizeof(T));
    std::memcpy(tmp.data(), &value, sizeof(T));
    f.Write(tmp);
    return f;
}

template<typename T>
File &operator>>(File &f, T &value)
{
    auto tmp = f.Read(sizeof(T));
    std::memcpy(&value, tmp.data(), sizeof(T));
    return f;
}
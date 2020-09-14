#pragma once

#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
/*
std::string GenerateClientUUID()
{
    static boost::uuids::random_generator generator;
    auto id = generator();

    return boost::lexical_cast<std::string>(id);
}

uint32_t GenerateClientId()
{
    std::srand(std::time(nullptr));
    return rand() % 10000000;
}
*/
template<typename T>
std::vector<uint8_t> ConvertToBytes(const T& data)
{
    std::vector<uint8_t> tmp(sizeof(T));
    std::memcpy(tmp.data(), &data, sizeof(T));
    return tmp;
}

template<>
std::vector<uint8_t> ConvertToBytes(const std::string& data)
{
    std::vector<uint8_t> result(data.size());
    std::memcpy(result.data(), data.data(), data.size());
    return result;
}

template<typename T>
T ConvertFromBytes(const std::vector<uint8_t>& data)
{
    T value;
    std::memcpy(&value, data.data(), sizeof(T));
}

template<>
std::string ConvertFromBytes(const std::vector<uint8_t>& data)
{
    std::string result(reinterpret_cast<const char *>(data.data()));
    return result;
}
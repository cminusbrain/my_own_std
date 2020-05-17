#pragma once
#include <socket/base_socket.h>
#include <vector>
#include <cstdint>

class IoSocket : public BaseSocket
{
public:

    IoSocket();

    explicit IoSocket(int fd);

    void Send(std::vector<uint8_t> data);

    std::vector<uint8_t> Receive(size_t size);

};


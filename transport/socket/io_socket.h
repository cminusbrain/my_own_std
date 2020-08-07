#pragma once
#include <transport/socket/base_socket.h>
#include <vector>
#include <cstdint>

class IoSocket : public BaseSocket
{
public:

    IoSocket();

    explicit IoSocket(int fd);

    IoSocket(IoSocket &&another) noexcept;

    IoSocket &operator=(IoSocket &&another) noexcept ;

    void Send(std::vector<uint8_t> data);


    std::vector<uint8_t> Receive(size_t size);

    friend void swap(IoSocket &first, IoSocket &second) noexcept
    {
        using std::swap;
        swap(static_cast<BaseSocket&>(first), static_cast<BaseSocket&>(second));
    }

};

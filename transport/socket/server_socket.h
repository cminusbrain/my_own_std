#pragma once
#include <transport/socket/base_socket.h>
#include <cstdint>
#include <transport/socket/io_socket.h>
#include <netinet/in.h>
#include <common/non_copyable.h>

class ServerSocket : public NonCopyable
{
public:

    ServerSocket() = default;

    explicit ServerSocket(uint16_t port);

    ServerSocket(ServerSocket &&another) noexcept;

    ServerSocket &operator=(ServerSocket &&another) noexcept;

    friend void swap(ServerSocket &first, ServerSocket &second) noexcept
    {
        using std::swap;
        swap(first.socket_, second.socket_);
        swap(first.address, second.address);
    }

    void Open();

    IoSocket Accept();

    BaseSocket::SocketStatus CheckForEvent();

private:

    BaseSocket socket_;
    sockaddr_in address{};

};


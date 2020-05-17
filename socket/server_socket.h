#pragma once
#include <socket/base_socket.h>
#include <cstdint>
#include <socket/io_socket.h>
#include <netinet/in.h>
#include <common/non_copyable.h>

class ServerSocket : public NonCopyable
{
public:

    ServerSocket() = default;

    explicit ServerSocket(uint16_t port);

    void Open();

    IoSocket Accept();

    void Close();

private:

    BaseSocket socket_;
    sockaddr_in address;

};


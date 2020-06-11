#pragma once
#include <transport/socket/io_socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

class ClientSocket : public IoSocket
{
public:

    ClientSocket();

    ClientSocket(const std::string &ip, uint16_t port);

    ClientSocket(ClientSocket &&another) noexcept;

    ClientSocket &operator=(ClientSocket &&another) noexcept;

    friend void swap(ClientSocket &first, ClientSocket &second) noexcept
    {
        using std::swap;
        swap(static_cast<BaseSocket&>(first), static_cast<BaseSocket&>(second));
        swap(first.address, second.address);
    }

    void Connect();

private:

    sockaddr_in address{};

};


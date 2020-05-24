#include <socket/server_socket.h>
#include <stdexcept>

ServerSocket::ServerSocket(uint16_t port) :
    socket_(socket(PF_INET, SOCK_STREAM, IPPROTO_TCP))
{
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    address.sin_family = PF_INET;
}

ServerSocket::ServerSocket(ServerSocket &&another) noexcept
{
    swap(*this, another);
}

ServerSocket &ServerSocket::operator=(ServerSocket &&another) noexcept
{
    swap(*this, another);
    return *this;
}


void ServerSocket::Open()
{
    if (bind(socket_.Native(), reinterpret_cast<sockaddr*>(&address), sizeof(address)) <  0)
    {
        throw std::runtime_error("bind failed");
    }
    if  (listen(socket_.Native(), 1) < 0)
    {
        throw std::runtime_error("listen failed");
    }
}

IoSocket ServerSocket::Accept()
{
    return IoSocket(accept(socket_.Native(), nullptr, nullptr));
}

void ServerSocket::Close()
{
    socket_.Close();
}

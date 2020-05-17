#include <socket/client_socket.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <socket/constants.h>
#include <stdexcept>

ClientSocket::ClientSocket() :
    IoSocket()
{}

ClientSocket::ClientSocket(const std::string &ip, uint16_t port) :
    IoSocket(socket(PF_INET, SOCK_STREAM, IPPROTO_TCP))
{
    inet_aton(ip.c_str(), &address.sin_addr);
    address.sin_port = htons(port);
    address.sin_family = PF_INET;
}

void ClientSocket::Connect()
{
    if(Native() == invalid_socket)
    {
        throw std::logic_error("invalid_socket at connect operation");
    }
    if (connect(Native(), reinterpret_cast<sockaddr*>(&address), sizeof(address)) < 0)
    {
        throw std::runtime_error("connection failed");
    }
}
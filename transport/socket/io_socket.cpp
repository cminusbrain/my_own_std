#include <transport/socket/io_socket.h>
#include <transport/socket/constants.h>
#include <stdexcept>
#include <sys/socket.h>

IoSocket::IoSocket() :
    BaseSocket()
{}

IoSocket::IoSocket(int fd) :
    BaseSocket(fd)
{}

IoSocket::IoSocket(IoSocket &&another) noexcept :
    IoSocket()
{
    swap(*this, another);
}

IoSocket &IoSocket::operator=(IoSocket &&another) noexcept
{
    swap(*this, another);
    return *this;
}

void IoSocket::Send(std::vector<uint8_t> data)
{
    if(Native() == invalid_socket)
    {
        throw std::logic_error("invalid_socket at send operation");
    }
    size_t bytes_sent = 0;
    while (bytes_sent < data.size())
    {
        ssize_t current_sent = send(Native(), data.data() + bytes_sent, data.size() - bytes_sent, MSG_NOSIGNAL);
        if(current_sent < 0)
        {
            throw std::runtime_error("failed send operation");
        }
        bytes_sent += current_sent;
    }
}

std::vector<uint8_t> IoSocket::Receive(size_t size)
{
    if(Native() == invalid_socket)
    {
        throw std::logic_error("invalid_socket at receive operation");
    }
    std::vector<uint8_t> data(size);
    size_t bytes_received = 0;
    while (bytes_received < size)
    {
        ssize_t current_received = recv(Native(), data.data() + bytes_received, size - bytes_received, MSG_NOSIGNAL);
        if (current_received < 0)
        {
            throw std::runtime_error("failed receive operation");
        }
        bytes_received += current_received;
    }
    return data;
}

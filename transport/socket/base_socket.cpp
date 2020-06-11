#include <transport/socket/base_socket.h>
#include <sys/socket.h>
#include <sys/poll.h>
#include <unistd.h>
#include <transport/socket/constants.h>
#include <stdexcept>

BaseSocket::BaseSocket() :
    socket_fd(invalid_socket)
{}

BaseSocket::BaseSocket(int fd) :
    socket_fd(fd)
{}

BaseSocket::BaseSocket(BaseSocket &&another) noexcept :
    BaseSocket()
{
    swap(*this, another);
}

BaseSocket &BaseSocket::operator=(BaseSocket &&another) noexcept
{
    swap(*this, another);
    return *this;
}

BaseSocket::~BaseSocket()
{
    Close();
}

void BaseSocket::Close()
{
    close(socket_fd);
}

int BaseSocket::Native()
{
    return socket_fd;
}

BaseSocket::SocketStatus BaseSocket::CheckForEvent()
{
    pollfd fds{Native(), POLLIN | POLLHUP, 0};

    int result = poll(&fds, 1, 100);

    switch (result)
    {
        case 0:
        {
            return SocketStatus::NoData;
        }
        case 1:
        {
            if(fds.revents & POLLIN != 0)
            {
                return SocketStatus::IncomingData;
            }
            if (fds.revents & POLLHUP != 0)
            {
                return SocketStatus::ConnectionLost;
            }
        }
        default:
        {
            throw std::runtime_error("Poll failed");
        }
    }
}
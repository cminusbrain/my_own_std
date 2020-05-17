#include <socket/base_socket.h>
#include <sys/socket.h>
#include <sys/poll.h>
#include <unistd.h>
#include <socket/constants.h>

BaseSocket::BaseSocket() :
    socket_fd(invalid_socket)
{}

BaseSocket::BaseSocket(int fd) :
    socket_fd(fd)
{}

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


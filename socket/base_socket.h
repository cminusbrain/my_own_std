#pragma once
#include <common/non_copyable.h>
#include <algorithm>

class BaseSocket : public NonCopyable
{
public:

    BaseSocket();

    explicit BaseSocket(int fd);

    BaseSocket(BaseSocket &&another) noexcept ;

    BaseSocket &operator=(BaseSocket &&another) noexcept ;

    ~BaseSocket();

    void Close();

    int Native();

    friend void swap(BaseSocket &first, BaseSocket &second) noexcept
    {
        using std::swap;
        swap(first.socket_fd, second.socket_fd);
    }

private:

    int socket_fd;

};
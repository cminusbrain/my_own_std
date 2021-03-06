#pragma once
#include <common/non_copyable.h>
#include <algorithm>

class BaseSocket : public NonCopyable
{
public:

    enum SocketStatus
    {
        IncomingData,
        NoData,
        ConnectionLost
    };

    BaseSocket();

    explicit BaseSocket(int fd);

    BaseSocket(BaseSocket &&another) noexcept ;

    BaseSocket &operator=(BaseSocket &&another) noexcept ;

    ~BaseSocket();

    void Close();

    int Native();

    SocketStatus CheckForEvent();

    void SetReuseOption(bool optionValue);

    friend void swap(BaseSocket &first, BaseSocket &second) noexcept
    {
        using std::swap;
        swap(first.socket_fd, second.socket_fd);
    }

private:

    int socket_fd;

};
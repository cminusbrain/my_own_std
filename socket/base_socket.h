#pragma once
#include <common/non_copyable.h>

class BaseSocket : public NonCopyable
{
public:

    BaseSocket();

    explicit BaseSocket(int fd);

    ~BaseSocket();

    void Close();

    int Native();

private:

    int socket_fd;

};
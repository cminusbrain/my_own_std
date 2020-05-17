#pragma once
#include <socket/io_socket.h>
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

    void Connect();

private:

    sockaddr_in address;

};


#pragma once
#include <transport/include/i_client.h>
#include <cstdint>
#include <netinet/in.h>
#include <transport/socket/client_socket.h>

class Client : public IClient
{
public:

    Client() = default;

    void Send(ClientId id, const std::string &message) override;

    void ConnectToServer(const std::string &ip, uint16_t port) override;

private:

    ClientSocket socket_;
};

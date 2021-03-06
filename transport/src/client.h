#pragma once
#include <transport/include/i_client.h>
#include <cstdint>
#include <netinet/in.h>
#include <transport/socket/client_socket.h>

class Client : public IClient
{
public:

    Client() = default;

    void Send(const std::string &message) override;

    std::vector<uint8_t> Receive(size_t size) override;

    void ConnectToServer(const std::string &ip, uint16_t port) override;

private:
    
    
    ClientSocket socket_;
};

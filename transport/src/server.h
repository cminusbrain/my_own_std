#pragma once
#include <transport/include/i_server.h>
#include <transport/socket/server_socket.h>

class Server : public IServer
{
public:

    explicit Server(uint16_t port);

    void Start() override;

    void Stop() override;

    void Restart() override;

    void Send(ClientId id, const std::string &message) override;

private:

    void WaitForConnectionRequest() override;

private:

    ServerSocket listener;
};
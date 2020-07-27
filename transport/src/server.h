#pragma once
#include <transport/include/i_server.h>
#include <transport/socket/server_socket.h>

#include <map>
#include <future>

class Server : public IServer
{
public:

    explicit Server(uint16_t port);

    void Start() override;

    void Stop() override;

    void Restart() override;

    void Send(ClientId id, const std::string &message) override;

    void WaitForConnectionRequest() override;

    void AcceptClient() override;

private:
    std::map<ClientId, std::shared_ptr<IoSocket>> clients_;
    ServerSocket listener;

    std::future<void> waitingThread_;
    std::future<void> acceptionThread_;
};
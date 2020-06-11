#pragma once
#include <string>
#include <cstdint>
#include <memory>

using ClientId = uint32_t;

class IServer
{
public:

    virtual void Start() = 0;

    virtual void Stop() = 0;

    virtual void Restart() = 0;

    virtual void Send(ClientId id, const std::string &message) = 0;

    virtual void WaitForConnectionRequest() = 0;

};

std::shared_ptr<IServer> CreateServer(uint16_t port);
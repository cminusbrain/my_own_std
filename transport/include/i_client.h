#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include <vector>

using ClientId = uint32_t;

class IClient
{
public:

    virtual void Send(ClientId id, const std::string &message) = 0;

    virtual std::vector<uint8_t> Receive(size_t size) = 0;

    virtual void ConnectToServer(const std::string &ip, uint16_t port) = 0;
};

std::shared_ptr<IClient> CreateClient();


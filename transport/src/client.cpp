#include <transport/src/client.h>
#include <iostream>
#include <common/helpers.h>

void Client::Send(const std::string &message)
{
    std::vector<uint8_t> dataToSend;
    auto serializedSize = ConvertToBytes(message.size());
    auto serializedData = ConvertToBytes(message);

    dataToSend.insert(dataToSend.end(), serializedSize.begin(), serializedSize.end());
    dataToSend.insert(dataToSend.end(), serializedData.begin(), serializedData.end());

    socket_.Send(dataToSend);
}

void Client::ConnectToServer(const std::string &ip, uint16_t port)
{
    try
    {
        socket_ = ClientSocket(ip, port);
        socket_.Connect();

        std::cout << "Client connected to " << ip << ':' << port << std::endl;
    }
    catch(std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}

std::vector<uint8_t> Client::Receive(size_t size)
{
    return socket_.Receive(size);
}

std::shared_ptr<IClient> CreateClient()
{
    return std::make_shared<Client>();
}

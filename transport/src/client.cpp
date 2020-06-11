#include <transport/src/client.h>
#include <iostream>

void Client::Send(ClientId id, const std::string &message)
{

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

std::shared_ptr<IClient> CreateClient()
{
    return std::make_shared<Client>();
}

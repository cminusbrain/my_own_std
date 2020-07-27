#include <transport/src/server.h>
#include <thread>
#include <chrono>

#include <iostream>

#include <common/helpers.h>


Server::Server(uint16_t port) :
    listener(port)
{}

void Server::Start()
{
    listener.Open();

    waitingThread_ = std::async(std::launch::async, &Server::WaitForConnectionRequest, this);
}

void Server::Stop()
{

}

void Server::Restart()
{
    Stop();
    Start();
}

void Server::Send(ClientId id, const std::string &message)
{
    auto socket = clients_.find(id)->second;

    std::vector<uint8_t> dataToSend;
    auto serializedSize = ConvertToBytes(message.size());
    auto serializedData = ConvertToBytes(message);

    dataToSend.insert(dataToSend.end(), serializedSize.begin(), serializedSize.end());
    dataToSend.insert(dataToSend.end(), serializedData.begin(), serializedData.end());

    socket->Send(dataToSend);
}

void Server::WaitForConnectionRequest()
{
    while(listener.CheckForEvent() != BaseSocket::IncomingData)
    {
        std::cout << "Waiting for client..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds (1000));
    }
    std::cout << "New client available!" << std::endl;
    acceptionThread_ = std::async(std::launch::async, &Server::AcceptClient, this);
}

void Server::AcceptClient()
{
    ClientId id = rand(); //GenerateClientId();
    std::cout << "New client ID = [" << id << "]" << std::endl;
    auto socket = std::make_shared<IoSocket>(listener.Accept());

    clients_.emplace(id, socket);

    Send(id, std::to_string(id));

    waitingThread_ = std::async(std::launch::async, &Server::WaitForConnectionRequest, this);
}

std::shared_ptr<IServer> CreateServer(uint16_t port)
{
    return std::make_shared<Server>(port);
}

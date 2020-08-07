#include <transport/src/server.h>
#include <thread>
#include <chrono>

#include <iostream>
#include <algorithm>

#include <common/helpers.h>


Server::Server(uint16_t port) :
    listener(port)
{}

Server::~Server()
{
    Stop();
}

void Server::Start()
{
    pollingThread_ = std::async(std::launch::async, &Server::StartSocketPolling, this);

    listener.Open();

    waitingThread_ = std::async(std::launch::async, &Server::WaitForConnectionRequest, this);
}

void Server::Stop()
{
    stop_ = true;
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
        //std::cout << "Waiting for client..." << std::endl;
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

void Server::StartSocketPolling()
{
    while(!stop_)
    {
        for(auto elem = clients_.begin(); elem != clients_.end(); elem++)
        {
            switch (elem->second->CheckForEvent())
            {
                case BaseSocket::SocketStatus::IncomingData:
                    AcceptMessage(elem->first);
                    break;
                case BaseSocket::SocketStatus::NoData:
                    continue;
                case BaseSocket::SocketStatus::ConnectionLost:
                    std::cout << "Client [" << elem->first << "] disconnected" << std::endl;
                    clients_.erase(elem);
                    break;
                default:
                    throw std::logic_error("Unknown socket status");
            }
        }
    }
}

void Server::AcceptMessage(ClientId id)
{
    size_t binaryMessageSize = ConvertFromBytes<size_t>(clients_[id]->Receive(sizeof(size_t)));
    auto binaryMessage = clients_[id]->Receive(binaryMessageSize);

    std::cout << "[" << id << "]: ";
    for(auto byte : binaryMessage)
    {
        std::cout << std::hex << static_cast<uint32_t>(byte) <<  ' ';
    }
    std::cout << std::dec << std::endl;
}

std::shared_ptr<IServer> CreateServer(uint16_t port)
{
    return std::make_shared<Server>(port);
}

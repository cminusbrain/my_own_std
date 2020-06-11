#include <transport/src/server.h>
#include <thread>
#include <chrono>

Server::Server(uint16_t port) :
    listener(port)
{}

void Server::Start()
{
    listener.Open();
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

}

void Server::WaitForConnectionRequest()
{
    while(listener.CheckForEvent() != BaseSocket::IncomingData)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds (1000));
    }
}

std::shared_ptr<IServer> CreateServer(uint16_t port)
{
    return std::make_shared<Server>(port);
}



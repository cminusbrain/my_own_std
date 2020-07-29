#include <transport/include/i_server.h>
#include <transport/include/constants.h>
#include <iostream>

int main()
{
    std::shared_ptr<IServer> server = CreateServer(serverPort);
    server->Start();

    std::cin.ignore();

    return 0;
}
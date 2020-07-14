#include <transport/include/i_server.h>
#include <transport/include/constants.h>
#include <transport/src/helpers.h>

int main()
{
    std::shared_ptr<IServer> server = CreateServer(serverPort);
    server->Start();
    server->WaitForConnectionRequest();
    server->AcceptClient();

    while(true){}
    return 0;
}
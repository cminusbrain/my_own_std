#include <iostream>

#include <transport/include/i_client.h>
#include <transport/include/constants.h>

#include <transport/src/helpers.h>

int main()
{
    auto client = CreateClient();
    client->ConnectToServer(serverIp, 9000);
    auto size = ConvertFromBytes<std::string::size_type>(client->Receive(sizeof(std::string::size_type)));
    auto id = ConvertFromBytes<std::string>(client->Receive(size));

    std::cout << id << std::endl;

    while (true){}
}
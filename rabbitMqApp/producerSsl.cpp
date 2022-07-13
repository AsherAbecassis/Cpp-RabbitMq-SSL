#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>

using namespace std;

int main()
{

    

    auto channel = AmqpClient::Channel::CreateSecure
    ("/Users/asherab/dev/apps/simpleamqpclientCPP/SimpleAmqpClient/rabbitMqApp/certificates3/ca.pem",
     "localhost",
      "/Users/asherab/dev/apps/simpleamqpclientCPP/SimpleAmqpClient/rabbitMqApp/certificates3/client-key.pem",
      "/Users/asherab/dev/apps/simpleamqpclientCPP/SimpleAmqpClient/rabbitMqApp/certificates3/client-cert.pem",
      5671,
      "test",
      "test",
      "/",
      13107222,
      false);
    std::string exchange_name = "my_exchange";
    std::string queue_name = channel->DeclareQueue("q_name", false, true, false, false);

    try
    {
         channel->BasicPublish(exchange_name,"/", AmqpClient::BasicMessage::Create("ssl message from producer"),true);
        
    }
    catch (const std::exception &e)
    {
         //// Here got exception: 'a socket error occurred'
    }
    return 0;
}
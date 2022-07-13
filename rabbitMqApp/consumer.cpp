#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>

using namespace std;

int main()
{
    auto channel = AmqpClient::Channel::Create("localhost", 5672, "test", "test");
    std::string exchange_name = "my_exchange";
    std::string queue_name = channel->DeclareQueue("q_name", false, true, false, false);

    try
    {
        std::string consumer_tag = channel->BasicConsume(queue_name, "", true, true, false, 1);

        auto envelope = channel->BasicConsumeMessage(consumer_tag); //// exception
        auto str = envelope->Message()->Body();
        // process the str...
        std::cout << str << std::endl;
        auto message = AmqpClient::BasicMessage::Create(str);
        message->DeliveryMode(AmqpClient::BasicMessage::dm_persistent);
        channel->BasicPublish(exchange_name, "", message);

        
        channel->BasicCancel(consumer_tag);
    }
    catch (const std::exception &e)
    {
        //// Here got exception: 'a socket error occurred'
    }
    return 0;
}
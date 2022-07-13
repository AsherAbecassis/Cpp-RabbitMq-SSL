#include <SimpleAmqpClient/SimpleAmqpClient.h>

#include <iostream>

using namespace std;

int main() {
  auto channel = AmqpClient::Channel::Create("localhost", 5672, "test", "test");
  std::string exchange_name = "my_exchange";
  std::string queue_name =
      channel->DeclareQueue("q_name", false, true, false, false);

  try {
    channel->BasicPublish(exchange_name, "",
                          AmqpClient::BasicMessage::Create("asher"), true);

  } catch (const std::exception &e) {
    //// Here got exception: 'a socket error occurred'
  }
  return 0;
}
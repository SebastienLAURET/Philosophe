#include <iostream>
#include <cstring>
#include "Fork.hpp"
#include "Semaphore.hpp"
#include "MsgHandler.hpp"
#include <unistd.h>
int main() {
  std::string path1("./philo1"), path2("./philo2");

  Fork f;
  f();
  if (f.isChildProcess()) {
    MsgHandler msgHand(path1, path2);
    msgHand.queueW.push(std::string("tototototo"));
    msgHand.queueW.push(std::string("tititititi"));
    sleep(1);
    msgHand.close();
    msgHand.join();
  } else {
    MsgHandler msgHand(path2, path1);
    sleep(1);
    while (msgHand.queueR.size()) {
      std::string str = msgHand.queueR.front();
      msgHand.queueR.pop();
      std::cout << str << '\n';
    }
    msgHand.close();
    msgHand.join();

    f.wait();
  }
  return 0;
}

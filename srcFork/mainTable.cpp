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
    MsgHandler  msgHand(path1, path2);
    Semaphore   sem;

    msgHand.queueW.push(std::string("tototototo"));
    msgHand.queueW.push(std::string("tititititi"));
    //sleep(1);
  //  sem(0, 1, 0);
    msgHand.close();
    std::cout << "close child" << '\n';
    msgHand.join();
    std::cout << "join child" << '\n';
  } else {
    MsgHandler msgHand(path2, path1);
    Semaphore   sem;

  //  sem(0, -1, 0);
    while (msgHand.queueR.size()) {
      std::string str = msgHand.queueR.front();
      msgHand.queueR.pop();
      std::cout << str << '\n';
    }
    msgHand.close();
    std::cout << "close " << '\n';
    msgHand.join();
    std::cout << "join " << '\n';
  }
  return 0;
}

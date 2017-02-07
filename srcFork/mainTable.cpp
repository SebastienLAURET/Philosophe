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
    sem.unlock(0);
    msgHand.close();
    msgHand.join();
  } else {

    MsgHandler msgHand(path2, path1);
    Semaphore   sem;

    sem.lock(0);
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

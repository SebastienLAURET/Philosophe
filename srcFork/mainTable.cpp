#include <iostream>
#include <cstring>
#include <unistd.h>
#include "Fork.hpp"
#include "Semaphore.hpp"
#include "MsgHandler.hpp"
#include "signalHandler.hpp"
#include "SHM.hpp"

int main() {
  SignalHandler signal;
  std::string path1("./philo1"), path2("./philo2");

  Fork f;
  f();

  SHM<int> test(".");

  test.write(0, 12);
  std::cout << test.read(0) << std::endl;

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

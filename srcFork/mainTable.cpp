#include <iostream>
#include <cstring>
#include "Fork.hpp"
#include "Semaphore.hpp"
#include "MsgQueue.hpp"

int main() {
  Fork  forkObj;
  MsgQueue  msgQObj;

  forkObj();
  if (forkObj.isChildProcess()) {
    Semaphore semObj;
    if (!msgQObj.isOpen()) {
      std::cerr << "Error :: MsgQueue" << std::endl;
      return 1;
    }
    int i = 0;
    while (i < 10) {
      msgQObj.send("hello word", 11, 0);
      ++i;
    }
  } else {
    Semaphore semObj;
    if (!msgQObj.isOpen()) {
      std::cerr << "Error :: MsgQueue" << std::endl;
      return 1;
    }
    char *test;
    test = new char[11];
    int ret  = 0;
    while (ret >= 0) {
      std::memset(test, 0, 11);
      ret = msgQObj.receve(test, 11, 0, 0);
      std::cout << ret  <<">>" << test << std::endl;
    }
    delete test;
  }
  return 0;
}

#include <iostream>
#include <cstring>
#include <unistd.h>
#include "Fork.hpp"
#include "Semaphore.hpp"
#include "signalHandler.hpp"
#include "SHM.hpp"

int main() {
  SignalHandler signal;
  std::string path1("./philo1"), path2("./philo2");

  Fork f;
  f();



  if (f.isChildProcess()) {
    Semaphore   sem(1);
    SHM<int> test(".");
    sleep(1);
    test.write(0, 12);
   sem.unlock(0);
  } else {
    SHM<int> test(".");
    Semaphore   sem(1);

    sem.lock(0);
    std::cout << test.read(0) << std::endl;
    f.wait();
  }
  return 0;
}

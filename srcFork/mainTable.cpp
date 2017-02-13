#include <iostream>
#include <list>
#include "Fork.hpp"
#include "Semaphore.hpp"
#include "signalHandler.hpp"
#include "SHM.hpp"

int main() {
  SignalHandler signal;
  std::list<Fork*> fList;
  size_t nbPhilo = 5;
  Fork *f;
  for (size_t i = 0; i < nbPhilo; i++) {
    f = new Fork();
    (*f)();
    if (f->isChildProcess()) {
      SHM<int> shm("./", nbPhilo);
      shm.write(i, i+3);
      break;
    } else
      fList.push_front(f);
    std::cout << "toto" << i << '\n';
  }

  if (!fList.front()->isChildProcess()) {
    SHM<int> shm("./", nbPhilo);
  //  while (!signal.getFlag()) {
      for (size_t i = 0; i < nbPhilo; i++) {
        std::cout << i <<":" << shm.read(i) << '\n';
      //  sleep(1);
      }
    //}
    while (fList.size()) {
      fList.front()->wait();
      delete fList.front();
      fList.pop_front();
    }
  } else {
    sleep(2);
  }
  return 0;
}

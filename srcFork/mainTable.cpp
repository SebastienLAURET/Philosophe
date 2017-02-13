#include <iostream>
#include <list>
#include "Execve.hpp"
#include "Fork.hpp"
#include "Semaphore.hpp"
#include "signalHandler.hpp"
#include "SHM.hpp"

int main(int ac, char *av[], char *env[]) {
  SignalHandler signal;
  std::list<Fork*> fList;
  size_t nbPhilo = 5;
  Fork *f;

  // Creation of Philosophes
  for (size_t i = 0; i < nbPhilo; i++) {
    f = new Fork();
    (*f)();
    fList.push_front(f);
    if (f->isChildProcess()) {
      SHM<int> shm("./", nbPhilo);

      shm.write(i, i + 3);
      std::cout << "Philosophe[" << i <<"] :" << "execve" << std::endl;
      std::vector<std::string> tmp;
      Execve exec(env);
      exec("./a.out", &tmp);
      break;
    }
  }

  if (!fList.front()->isChildProcess()) {
    SHM<int> shm("./", nbPhilo);
  //  while (!signal.getFlag()) {
      for (size_t i = 0; i < nbPhilo; i++) {
        std::cout << "Philosophe[" << i <<"] :" << shm.read(i) << '\n';
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

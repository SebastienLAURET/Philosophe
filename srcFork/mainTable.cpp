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
      std::vector<std::string> tmp;
      tmp.push_back("a.out");
      tmp.push_back(std::to_string(nbPhilo));
      tmp.push_back(std::to_string(i));

      Execve exec(env);
      exec("./philo", &tmp);
    }
    std::cout << std::endl;
    sleep (1);
  }
  SHM<int> shm("./", nbPhilo);
  /*
//while (!signal.getFlag()) {
    for (size_t i = 0; i < nbPhilo; i++) {
      std::cout << "Philosophe[" << i <<"] :" << shm.read(i) << '\n';
    //  sleep(1);
    }
//  }
*/
  while (fList.size()) {
    fList.front()->wait();
    delete fList.front();
    fList.pop_front();
  }
  return 0;
}

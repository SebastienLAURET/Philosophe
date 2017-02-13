#include <iostream>
#include <list>
#include "Philosophe.hpp"
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

  //No more warning
  (void)ac;
  (void)av;

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

  while (!signal.getFlag()) {
    for (size_t i = 0; i < nbPhilo; i++) {
      std::cout << "[" << i <<"]: ";
      switch (shm.read(i)) {
        case Philosophe::SLEEP:
          std::cout <<  "SLEEP";
          break;
        case Philosophe::EAT:
          std::cout <<  "EAT  ";
          break;
        case Philosophe::THINK:
          std::cout <<  "THINK";
          break;
        default:
          break;
      }
      std::cout << " ";
      usleep(1000);
    }
    std::cout << std::endl;
  }
  while (fList.size()) {
    fList.front()->wait();
    delete fList.front();
    fList.pop_front();
  }
  return 0;
}

#ifndef PHILOSOPHE_HPP
# define PHILOSOPHE_HPP

#include <thread>
#include <mutex>
#include <sstream>
#include "SHM.hpp"
#include "Semaphore.hpp"

class Philosophe {

public:
  enum e_state {
    THINK,
    EAT,
    SLEEP
  };

  Philosophe(size_t id, size_t maxPhilo);
  ~Philosophe();

  void          operator()();
  e_state       getState();

private:
  void          think(bool);
  void          eat();
  void          sleep();
  void          displayState();

  size_t                    _id;
  size_t                    _maxPhilo;
  SHM<Philosophe::e_state>  _shm;
  Semaphore                 _sem;
};

#endif //PHILOSOPHE_HPP

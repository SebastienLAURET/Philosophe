#ifndef PHILOSOPHE_HPP
# define PHILOSOPHE_HPP

#include <thread>
#include <mutex>
#include <sstream>
#include "Display.hpp"

class Philosophe {

public:
  enum e_state {
    THINK,
    EAT,
    SLEEP
  };

  Philosophe(std::mutex&, std::mutex&,
             int id, Display &disp);
  ~Philosophe();

  void          operator()();
  void          run();
  void          join();
  e_state       getState();
  void          setPhiloG(Philosophe *philo);
  void          setPhiloD(Philosophe *philo);
  static void   trampoline(Philosophe*);
private:
  void          think(bool);
  void          eat();
  void          sleep();
  void          displayState();

  std::mutex    &_baguetteG;
  std::mutex    &_baguetteD;

  Philosophe    *_philoG;
  Philosophe    *_philoD;

  e_state       _state;
  int           _id;
  Display       &_disp;
  std::thread   _thread;
};

#endif //PHILOSOPHE_HPP

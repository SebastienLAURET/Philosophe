#ifndef PHILOSOPHE_HPP
# define PHILOSOPHE_HPP

#include <thread>
#include <mutex>
#include "Display.hpp"

class Philosophe : public std::thread {

public:
  enum e_state {
    THINK,
    EAT,
    SLEEP
  };

  Philosophe(std::pair<std::mutex&, std::mutex&> &bag,
             std::pair<Philosophe&, Philosophe&> &philo,
             int id, Display &disp);
  ~Philosophe();

  void          operator()();
  e_state       getState();
  static void   trampoline(Philosophe &);
private:
  typedef std::pair<Philosophe&,Philosophe&> philoPaire;
  typedef std::pair<std::mutex&,std::mutex&> paireBag;
  void          think(bool);
  void          eat();
  void          sleep();
  void          displayState();

  std::mutex    &_baguetteG;
  std::mutex    &_baguetteD;

  Philosophe    &_philoG;
  Philosophe    &_philoD;

  e_state       _state;
  int           _id;
  Display       &_disp;
};

#endif //PHILOSOPHE_HPP

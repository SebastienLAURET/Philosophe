#include "Philosophe.hpp"

/*
** public
*/

/*
**  constructor
*/
Philosophe::Philosophe(std::pair<std::mutex&, std::mutex&> &bag,
           std::pair<Philosophe&, Philosophe&> &philo,
           int id, Display &disp)
: _baguetteG(bag.first), _baguetteD(bag.second),
  _philoG(philo.first), _philoD(philo.second),
  _state(SLEEP), _id(id), _disp(disp) {

}
Philosophe::~Philosophe() {

}


void      Philosophe::operator()() {
  bool    bagGIsLock;
  bool    bagDIsLock;

  while (true) {
      bagGIsLock = this->_baguetteG.try_lock();
      bagDIsLock = this->_baguetteD.try_lock();
      if (bagDIsLock &&  bagGIsLock) {
        this->eat();
      } else if (bagGIsLock || bagDIsLock) {
        this->think(bagGIsLock);
      }
  }
}

Philosophe::e_state   Philosophe::getState() {
  return this->_state;
}

void      Philosophe::trampoline(Philosophe &philo) {
//  Philosophe &philo = *self;
  philo();
}

/*
** private
*/

void      Philosophe::think (bool selBag) {
  this->_state = THINK;

  if (selBag) {
    _baguetteG.lock();
  } else {
    _baguetteD.lock();
  }
  this->eat();
}

void      Philosophe::eat () {
  this->_state = EAT;

  this->_baguetteG.unlock();
  this->_baguetteD.unlock();

  this->sleep();
}

void      Philosophe::sleep() {
  this->_state = SLEEP;

  while (this->_philoG.getState() == THINK
        && this->_philoD.getState() == THINK);
}

void      Philosophe::displayState() {
  std::string str;
  std::string statesTab[3] = {
    "THINK",
    "EAT",
    "SLEEP"
  };

//  str << "Philosophe " << this->_id << " : " << statesTab[(int)this->_state];
  _disp.print(this->_id, str);
}

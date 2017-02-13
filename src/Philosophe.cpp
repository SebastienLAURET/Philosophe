#include "Philosophe.hpp"

/*
** public
*/

/*
**  constructor
*/
Philosophe::Philosophe(std::mutex &bagG, std::mutex &bagD,
                      int id, Display &disp)
: _baguetteG(bagG), _baguetteD(bagD),
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
      } else if ((bagGIsLock || bagDIsLock)  ) {
        this->think(bagGIsLock);
      }
  }
}

Philosophe::e_state   Philosophe::getState() {
  return this->_state;
}

void      Philosophe::setPhiloG(Philosophe *philo) {
  this->_philoG = philo;
}

void      Philosophe::setPhiloD(Philosophe *philo) {
  this->_philoD = philo;
}

void      Philosophe::run() {
  this->_thread = std::thread(Philosophe::trampoline, this);
}

void      Philosophe::join() {
  this->_thread.join();
}

void      Philosophe::trampoline(Philosophe *self) {
  Philosophe &philo = *self;
  philo();
}

/*
** private
*/

void      Philosophe::think (bool selBag) {
  this->_state = THINK;
  this->displayState();

  if (selBag) {
    _baguetteD.lock();
  } else {
    _baguetteG.lock();
  }
  this->eat();
}

void      Philosophe::eat () {
  this->_state = EAT;
  this->displayState();
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  this->_baguetteG.unlock();
  this->_baguetteD.unlock();

  this->sleep();
}

void      Philosophe::sleep() {
  this->_state = SLEEP;
  this->displayState();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));

  while (this->_philoG->getState() == THINK
        && this->_philoD->getState() == THINK);
}

void      Philosophe::displayState() {
  std::stringstream str;
  std::string statesTab[3] = {
    "THINK ",
    "EAT   ",
    "SLEEP "
  };

  str << "Philosophe ";
  str << this->_id;
  str << " : ";
  str << statesTab[(int)this->_state];

  _disp.print(this->_id, str.str());
}

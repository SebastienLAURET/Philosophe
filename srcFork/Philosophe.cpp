#include "Philosophe.hpp"
#include "signalHandler.hpp"
/*
** public
*/

/*
**  constructor
*/
Philosophe::Philosophe(size_t id, size_t maxPhilo)
 : _id(id), _maxPhilo(maxPhilo), _shm("./", maxPhilo), _sem(maxPhilo){
  _shm.write(_id, Philosophe::SLEEP);
}

Philosophe::~Philosophe() {
}

void      Philosophe::operator()() {
  bool          bagGIsLock;
  bool          bagDIsLock;
  SignalHandler handler;

  while (!handler.getFlag()) {
      bagGIsLock = _sem.tryLock(_id);
      bagDIsLock = _sem.tryLock((_id + 1) % _maxPhilo);

  //    std::cout << " "<< bagGIsLock << " "<< bagDIsLock << std::endl;

      if (bagDIsLock && bagGIsLock) {
        this->eat();
      } else if ((bagGIsLock || bagDIsLock)) {
        this->think(bagGIsLock);
      }
//      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

Philosophe::e_state   Philosophe::getState() {
  return _shm.read(_id);
}
/*
** private
*/

void      Philosophe::think (bool selBag) {
  _shm.write(_id, Philosophe::THINK);

  if (selBag) {
    _sem.lock((_id + 1) % _maxPhilo);
  } else {
    _sem.lock(_id);
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  this->eat();
}

void      Philosophe::eat () {
  _shm.write(_id, Philosophe::EAT);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  _sem.unlock(_id);
  _sem.unlock((_id + 1) % _maxPhilo);

  this->sleep();
}

void      Philosophe::sleep() {
  _shm.write(_id, Philosophe::SLEEP);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  while (_shm.read(((_id - 1) < 0) ? _maxPhilo : _id - 1) == Philosophe::THINK
        && _shm.read((_id + 1) % _maxPhilo) == THINK);
}

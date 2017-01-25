#include "Handler.hpp"

Handler::Handler(int nb)
: _philos(nb), _bag(nb)  {
  for (size_t iter = 0; iter < nb; iter++) {
    _bag[iter] = new std::mutex();
  }
  for (size_t iter = 0; iter < nb; iter++) {
    _philos[iter] = new Philosophe(*_bag[iter], *_bag[(iter + 1)% nb],
                                  iter, _disp);
  }
  for (size_t iter = 0; iter < nb; iter++) {
    _philos[iter]->setPhiloG(_philos[(iter - 1)% nb]);
    _philos[iter]->setPhiloD(_philos[(iter + 1)% nb]);
  }
}

Handler::~Handler() {
  for (size_t iter = 0; iter < _bag.size(); iter++) {
    delete _bag[iter];
    delete _philos[iter];
  }
}

void Handler::run() {
  for (size_t iter = 0; iter < _bag.size(); iter += 2) {
    _philos[iter]->run();
  }
  for (size_t iter = 1; iter < _bag.size(); iter += 2) {
    _philos[iter]->run();
  }
  for (size_t iter = 0; iter < _bag.size(); iter++) {
    _philos[iter]->join();
  }

}

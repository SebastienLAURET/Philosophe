#include "Display.hpp"

Display::Display() {
  tgetent(NULL, NULL);
  putp(tgetstr("cl", NULL));
}

Display::~Display() {

}

void Display::print(int id, std::string const &str) {
  this->_mtx.lock();
  putp(tgoto(tgetstr("cm", NULL), 0, id));
  std::cout << str << std::endl;
  this->_mtx.unlock();
}

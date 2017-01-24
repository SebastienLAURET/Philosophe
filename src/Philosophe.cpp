#include "Philosophe.hpp"

Philosophe::Philosophe(std::mutex &bagG, std::mutex &bagD)
: _baguetteG(bagG), _baguetteD(bagD) {

}
Philosophe::~Philosophe() {

}

void Philosophe::operator()(Philosophe &self) {

}

void Philosophe::trampoline(Philosophe *self) {

}

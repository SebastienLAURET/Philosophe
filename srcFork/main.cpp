#include <iostream>
#include <cstdlib>
#include "Philosophe.hpp"

int main (int ac, char* av[]){
  // No more warnings
  (void) ac;
  Philosophe philo(std::atoi(av[2]), std::atoi(av[1]));
  philo();
  return (0);
}

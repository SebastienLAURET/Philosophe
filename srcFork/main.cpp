#include <iostream>
#include <cstdlib>
#include "Philosophe.hpp"

int main (int ac, char* av[]){
  // No more warnings
  (void) ac;
  std::cout << "AV[1] : " << av[1] << std::endl;
  std::cout << "AV[2] : " << av[2] << std::endl;
  Philosophe philo(std::atoi(av[2]), std::atoi(av[1]));
  philo();
  std::cout << "end : " << av[1] << std::endl;
  return (0);
}

#include "Execve.hpp"
#include <iostream>

Execve::Execve(char **env) {
  _env = env;
}

Execve::~Execve(){
}

void Execve::operator()(const std::string &filename, std::vector<std::string> *argVector){
  char **args;
  int i = 0;

  if (argVector) {
   args = new char*[argVector->size()];

   for (auto arg : (*argVector))
    args[i++] = const_cast<char*>(arg.c_str());
  }

  std::cout << execve(filename.c_str(), args, _env) << std::endl;
  if (argVector)
    delete args;
}

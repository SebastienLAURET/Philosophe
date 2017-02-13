#include "Execve.hpp"
#include "cstring"
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
   args = new char*[argVector->size() + 1];

   for (auto arg : (*argVector)) {
     args[i] = new char[arg.size() + 1];
     std::memset(args[i], 0, arg.size() + 1);
     std::memcpy(args[i], arg.c_str(), arg.size());
    ++i;
   }
  }
  args[i] = NULL;

  execve(filename.c_str(), args, _env);
  if (argVector)
    delete args;
}

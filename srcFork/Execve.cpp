#include "Execve.hpp"

Execve::Execve(char **env) {
  _env = env;
}

Execve::~Execve(){
}

void Execve::operator()(const std::string &filename, std::vector<std::string> *argVector){
  char **args = new char*[argVector->size()];
  int i = 0;
  for (auto arg : (*argVector)) {
    args[i++] = const_cast<char*>(arg.c_str());
  }
  execve(filename.c_str(), args, _env);
  delete args;
}

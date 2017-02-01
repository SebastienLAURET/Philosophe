
#ifndef EXECVE_HPP
# define EXECVE_HPP

#include <string>
#include <vector>
#include <unistd.h>

class Execve {
private:
  char **_env;

public:
  Execve(char **env);
  ~Execve();

  void operator()(const std::string &filename, std::vector<std::string> *argVector = NULL);
};

#endif //!EXECVE_HPP

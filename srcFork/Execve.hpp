
#ifndef EXECVE_HPP
# define EXECVE_HPP
# include <unistd.h>

class Execve {
private:
  char *_envp[];
  char *_argv[];

public:
  Execve(char *env[], char *argv[]) {
    _env = env;
    _argv = argv;
  }

  ~Execve(){
  }

  void run(const std::string filename){
    execve(filename.c_str(), _argv, _envp);
  }
};

#endif //!EXECVE_HPP

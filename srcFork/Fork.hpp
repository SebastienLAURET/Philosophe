#ifndef FORK_HPP
# define FORK_HPP

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

class Fork {
public:
  Fork();
  ~Fork();

  bool  operator()();

  bool  isChildProcess();
  int   getPID();
  int   wait(int);
  bool  killChild();

private:
  pid_t _childPID;
};

#endif //!FORK_HPP

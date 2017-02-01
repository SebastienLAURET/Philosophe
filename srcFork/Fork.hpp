#ifndef FORK_HPP
# define FORK_HPP

#include <unistd.h>

class Fork {
public:
  Fork();
  ~Fork();

  bool  operator()( );

  bool  isChildProcess();
  int   getPID();

private:
  int _childPID;
};

#endif //!FORK_HPP

#include "Fork.hpp"

Fork::Fork() {
  _childPID = 0;
}

Fork::~Fork() {
  killChild();
}

bool  Fork::operator()() {
  _childPID = fork();
  return (_childPID >= 0);
}

bool  Fork::isChildProcess() {
  return (_childPID == 0);
}

int   Fork::getPID() {
  return _childPID;
}

int  Fork::wait() {
  if (!isChildProcess()) {
    int status = 0;
    if (waitpid(_childPID, &status, 0) == -1);
      return -1;
    return WEXITSTATUS(status);
  }
  return 0;
}

bool Fork::killChild() {
  if (!isChildProcess() && _childPID > 0) {
    kill(_childPID, 9);
    _childPID = 0;
  }
  return false;
}

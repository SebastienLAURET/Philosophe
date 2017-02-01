#include "Fork.hpp"

Fork::Fork() {

}

Fork::~Fork() {

}

bool  operator()() {
  _childPID = fork();
  return (_childPID >= 0);
}

bool  isChildProcess() {
  return (pid == 0)
}

int   getPID() {
  return _childPID;
}

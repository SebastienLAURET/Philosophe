#ifndef SHM_HPP
# define SHM_HPP

#include <iostream>
#include <string>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>

class SHM {
public:
  SHM(std::string &path, int flag = (SHM_R | SHM_W));
  ~SHM();

  bool  isOpen();
  bool  init(std::string &path, int flag = (SHM_R | SHM_W));



  bool  close();

private:

};

#endif //!SHM_HPP

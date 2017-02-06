#ifndef SEMAPHORE_HPP
# define SEMAPHORE_HPP

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

class Semaphore {
private:
  sembuf  _op;
  key_t   _key;
  int     _semId;

public:
  Semaphore();
  ~Semaphore();

  void operator()(int seim_num, int sem_op, int sem_flg);
};

#endif //!SEMAPHORE_HPP

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
  size_t  _nb;

public:
  Semaphore(int nb);
  ~Semaphore();

  void lock(int);
  void unlock(int);
  bool tryLock(int);
  int operator()(int seim_num, int sem_op, int sem_flg);
};

#endif //!SEMAPHORE_HPP

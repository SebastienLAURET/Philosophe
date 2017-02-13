#include <iostream>
#include "Semaphore.hpp"

Semaphore::Semaphore(int nb) {
  _key = ftok("./", 'c');
  _nb = nb;
  if ((_semId = semget(_key, _nb, SHM_R | SHM_W)) <= 0) {
    _semId = semget(_key, _nb, IPC_CREAT | SHM_R | SHM_W);
    for (size_t i = 0; i < _nb; i++) {
      /* code */
      semctl(_semId, i, SETVAL, 1);
    }
  }
  std::cout << "id Sem :"<< _key << " " << _semId << '\n';
}

Semaphore::~Semaphore() {
  for (size_t i = 0; i < _nb; i++) {
    /* code */
    semctl(_semId, _nb, IPC_RMID, 0);
  }
}

void Semaphore::lock(int sem_num){
    (*this)(sem_num, -1, SEM_UNDO);
}

void Semaphore::unlock(int sem_num){
  (*this)(sem_num, 1, SEM_UNDO);
}

bool Semaphore::tryLock(int sem_num) {
//  std::cout << "Try sem : "<< sem_num << "  "<< semctl(_semId, sem_num, GETVAL) << std::endl;
  if (semctl(_semId, sem_num, GETVAL) > 0) {
    lock(sem_num);
    return true;
  }
  return false;
}

int Semaphore::operator()(int sem_num, int sem_op, int sem_flg) {
    _op.sem_num = sem_num;
    _op.sem_op = sem_op;
    _op.sem_flg = sem_flg;
    return semop(_semId, &_op, 1);
}

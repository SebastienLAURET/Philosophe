#include <iostream>
#include "Semaphore.hpp"

Semaphore::Semaphore(int nb) {
  _key = ftok("./", 0);
  if ((_semId = semget(_key, nb, SHM_R | SHM_W)) <= 0) {
    _semId = semget(_key, nb, IPC_CREAT | SHM_R | SHM_W);
    semctl(_semId, 0, SETALL, 1);
  }
  std::cout << "id Sem :"<< _key << " " <<_semId<< '\n';
}

Semaphore::~Semaphore() {
  semctl(_semId, 0, IPC_RMID, 0);
}

void Semaphore::lock(int sem_num){
    (*this)(sem_num, -1, SEM_UNDO);
}

void Semaphore::unlock(int sem_num){
  (*this)(sem_num, 1, SEM_UNDO);
}

bool Semaphore::tryLock(int sem_num) {
  if (semctl(_semId, sem_num, GETVAL) > 0) {
    unlock(sem_num);
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

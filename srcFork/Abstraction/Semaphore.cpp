#include <iostream>
#include "Semaphore.hpp"

Semaphore::Semaphore() {
  _key = ftok("./", 'd');
  if ((_semId = semget(_key, 1, SHM_R | SHM_W)) <= 0) {
    _semId = semget(_key, 1, IPC_CREAT | SHM_R | SHM_W);
    semctl(_semId, 0, SETALL, 1);
  }
  std::cout << "id Sem :"<< _key << " " <<_semId<< '\n';
}

Semaphore::~Semaphore() {
  semctl(_semId, 0, IPC_RMID, 0);
}

int Semaphore::operator()(int sem_num, int sem_op, int sem_flg) {
    _op.sem_num = sem_num;
    _op.sem_op = sem_op;
    _op.sem_flg = sem_flg;
    return semop(_semId, &_op, 1);
  }

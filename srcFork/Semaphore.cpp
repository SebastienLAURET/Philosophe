#include "Semaphore.hpp"

Semaphore::Semaphore() {
  _key = ftok(".", ID_PROJECT);
  _semId = semget(_key, 1, IPC_CREAT | IPC_EXCL | 0666);
  semctl(_semId, 0, SETVAL, 1);
}

Semaphore::~Semaphore() {
  semctl(_semId, 0, IPC_RMID, 0);
}

void Semaphore::operator()(int sem_num, int sem_op, int sem_flg) {
    _op.sem_num = sem_num;
    _op.sem_op = sem_op;
    _op.sem_flg = sem_flg;
    semop(_semId, &_op, 1);
  }

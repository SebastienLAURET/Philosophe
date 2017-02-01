#ifndef SEMAPHORE_HPP
# define SEMAPHORE_HPP
# define ID_PROJECT 'P';

class Semaphore {
private:
  sembuf  _op;
  key_t   _key;
  int     _semId;

public:
  Semaphore() {
    _key = ftok(".", ID_PROJECT);
    _semId = semget(_key, 1, IPC_CREATE | IPC_EXCL | 0666);
    semctl(_semId, 0, SET_VAL, 1);
  }
  ~Semaphore() {
    semctl(_semId, 0, IPC_RMID, 0);
  }

  void op(int seim_num, int sem_op, int sem_flg) {
      _op.sem_num = sem_num;
      _op.sem_op = sem_op;
      _op.sem_flg = sem_flg;
      semop(_semId, &op, 1);
    }
};

#endif //!SEMAPHORE_HPP

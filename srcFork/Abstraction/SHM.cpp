#include "SHM.hpp"

SHM::SHM(std::string &str, int flag) {
  _msgId = 0;
  init(str, flag);
}
SHM::~SHM() {
  close();
}

bool SHM::isOpen() {
  return (_msgId > 0);
}

bool SHM::init(std::string &path, int flag) {
  key_t key = ftok(path.c_str(), 'm');
  _msgId = shmget(key, flag);
  if (_msgId == -1) {
    _shmId = shmget(key, IPC_CREAT | SHM_R | SHM_W);
  }
  _ptr = shmat(_shmId, NULL, flag))
  return isOpen();
}

template<typename T>
void write(size_t index, T value) {
  T tmpPtr = static_cast<T>(_ptr);
  tmpPtr[index] = value;
}

template<typename T>
T read(int index) {
  T tmpPtr = static_cast<T>(_ptr);
  return tmpPtr[index];
}


bool SHM::close() {
  int ret = shmdt(_ptr);
  _msgId = 0;
  return (ret >= 0);
}

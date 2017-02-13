#ifndef SHM_HPP
# define SHM_HPP

#include <iostream>
#include <string>

#include <sys/types.h>
#include <sys/shm.h>

template<typename T>
class SHM {
public:

  SHM(const std::string str, int flag = (SHM_W | SHM_R)) {
    _shmId = 0;
    init(str, flag);
  }

  ~SHM() {
    close();
  }

  bool isOpen() {
    return (_shmId > 0);
  }

  bool init(const std::string &path, int flag = (SHM_W | SHM_R)) {
    key_t key = ftok(path.c_str(), 's');
    _shmId = shmget(key, 5 * sizeof(T), flag);
    if (_shmId == -1) {
      _shmId = shmget(key, 5 * sizeof(T), IPC_CREAT | SHM_R | SHM_W);
    }
    _ptr = static_cast<T*>(shmat(_shmId, NULL, flag));
    return isOpen();
  }

  bool close() {
    int ret = shmdt(_ptr);
    _shmId = 0;
    return (ret >= 0);
  }

  void write(size_t index, T value) {
    _ptr[index] = value;
  }

  T read(int index) {
    return _ptr[index];
  }

private:
  int _shmId;
  T* _ptr;
};

#endif //!SHM_HPP

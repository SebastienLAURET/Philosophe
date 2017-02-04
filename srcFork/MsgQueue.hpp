#ifndef MSGQUEUE_HPP
# define MSGQUEUE_HPP

#include <iostream>
#include <string>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>

class MsgQueue {
public:
  MsgQueue();
  ~MsgQueue();

  bool  isOpen();
  bool  init(std::string &path);
  int   send(const void *msgp, size_t msgsz, int msgflg);
  int   receve(void *msgp, size_t msgsz, long msgtyp, int msgflg);
  bool  close();

private:
  ssize_t _msgId;
};

#endif //!MSGQUEUE_HPP

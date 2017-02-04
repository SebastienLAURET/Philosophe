#include "MsgQueue.hpp"

MsgQueue::MsgQueue() {
  _msgId = 0;
  std::string strTmp("./");
  init(strTmp);
}
MsgQueue::~MsgQueue() {
  close();
}

bool MsgQueue::isOpen() {
  return (_msgId > 0);
}

bool MsgQueue::init(std::string &path) {
  key_t key = ftok(path.c_str(),0);
  _msgId = msgget(key, SHM_R | SHM_W);
  if (_msgId == -1) {
    _msgId = msgget(key, IPC_CREAT | SHM_R | SHM_W);
  }
  std::cout << _msgId << std::endl;
  return isOpen();
}

int MsgQueue::send(const void *msgp, size_t msgsz, int msgflg) {
  return msgsnd(_msgId, msgp, msgsz, msgflg);
}

int MsgQueue::receve(void *msgp, size_t msgsz, long msgtyp, int msgflg) {
  return msgrcv(_msgId, msgp, msgsz, msgtyp, msgflg);
}

bool MsgQueue::close() {
  int ret = msgctl(_msgId, IPC_RMID, 0);
  _msgId = 0;
  return (ret >= 0);
}

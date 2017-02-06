
#include "MsgHandler.hpp"

MsgHandler::MsgHandler(std::string &path1, std::string &path2)
: std::thread(MsgHandler::trampoline, this),
 _msgQObjR(path1, SHM_R), _msgQObjW(path2, SHM_W) {

}

MsgHandler::~MsgHandler() {

}

void MsgHandler::operator()() {
  _endFlag = true;

  while (_endFlag) {
    _receve();
    _send();
  }
}

void MsgHandler::close() {
  _endFlag = false;
}

void MsgHandler::trampoline(MsgHandler *tmp){
  (*tmp)();
}


void MsgHandler::_receve() {
    if (!_msgQObjR.isOpen()) {
      std::cerr << "Error : <MsgHandler::_receve> Msg Queue isn't open" << std::endl;
      return;
    }
    int ret;
    char *strTmp = new char[11];

    std::memset(strTmp, 0, 11);
    while ((ret = _msgQObjR.receve(strTmp, 11, 0, IPC_NOWAIT)) > 0) {
      queueR.push(std::string(strTmp, 11));
      std::memset(strTmp, 0, 11);
    }
    delete strTmp;
}

void MsgHandler::_send() {
  if (!_msgQObjW.isOpen()) {
    std::cerr << "Error : <MsgHandler::_receve> Msg Queue isn't open" << std::endl;
    return;
  }
  while (queueW.size()) {
    std::string str = queueW.front();
    queueW.pop();
    _msgQObjW.send(str.c_str(), 11, 0);
  }
}

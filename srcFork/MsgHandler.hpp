#ifndef MSGHANDLER_HPP
# define MSGHANDLER_HPP

#include <iostream>
#include <thread>
#include <cstring>
#include <queue>
#include "MsgQueue.hpp"

class MsgHandler : public std::thread {
public:
    MsgHandler(std::string&, std::string&);
    ~MsgHandler();

    void          operator()();
    void          close();
    static void   trampoline(MsgHandler*);

    std::queue<std::string>    queueW;
    std::queue<std::string>    queueR;
private:
  void            _receve();
  void            _send();

  volatile bool _endFlag;
  MsgQueue      _msgQObjR;
  MsgQueue      _msgQObjW;

};

#endif //!MSGHANDLER_HPP

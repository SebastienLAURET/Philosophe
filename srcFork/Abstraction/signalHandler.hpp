#ifndef SIGNALHANDLER_HPP
# define SIGNALHANDLER_HPP

#include <atomic>
#include <csignal>

std::atomic<bool> flag_g;

class SignalHandler {
public:
  SignalHandler() {
    flag_g = false;
    if (std::signal(SIGINT, &SignalHandler::ctrl_c) == SIG_ERR)
    {
      std::cerr << "Error: init signal" << std::endl;
    }
  }

  bool getFlag(){
    return flag_g;
  }

  static void ctrl_c(int){
    flag_g = true;
  }
private:
};

#endif

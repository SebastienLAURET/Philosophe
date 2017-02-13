#ifndef SIGNALHANDLER_HPP
# define SIGNALHANDLER_HPP

#include <atomic>
#include <csignal>

std::atomic<bool> flagExit_g;

class SignalHandler {
public:
  SignalHandler() {
    flagExit_g = false;
    if (std::signal(SIGINT, &SignalHandler::ctrl_c) == SIG_ERR)
    {
      std::cerr << "Error: init signal" << std::endl;
    }
  }

  bool getFlag(){
    return flagExit_g;
  }

  static void ctrl_c(int){
    flagExit_g = true;
  }
private:
};

#endif

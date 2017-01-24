#ifndef HANDLER_HPP
# define HANDLER_HPP

#include <vector>
#include <mutex>
#include "Display.hpp"
#include "Philosophe.hpp"

class Handler {
  public:
    Handler(int);
    ~Handler();

    void run();

  private:
    Display                   _disp;
    std::vector<Philosophe*>  _philos;
    std::vector<std::mutex*>  _bag;
};

#endif //HANDLER_HPP

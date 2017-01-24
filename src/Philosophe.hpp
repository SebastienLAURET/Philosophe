#ifndef PHILOSOPHE_HPP
# define PHILOSOPHE_HPP

#include <thread>
#include <mutex>

class Philosophe : public std::thread {
private:
  std::mutex &_baguetteG;
  std::mutex &_baguetteD;

public:
  Philosophe(std::mutex &, std::mutex &);
  ~Philosophe();

  void operator()(Philosophe &);

  static void trampoline(Philosophe *);
  enum e_state {
    THINK,
    EAT,
    SLEEP
  };
};

#endif //PHILOSOPHE_HPP

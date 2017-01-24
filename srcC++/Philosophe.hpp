#ifndef PHILOSOPHE_HPP
# define PHILOSOPHE_HPP

#include <thread>
#include <mutex>


class Philosophe : public std::thread {
public:
  enum e_state {
    THINK,
    EAT,
    SLEEP
  };

  typedef std::pair<std::mutex &, std::mutex &> s_pairBag;
  typedef std::pair<Philosophe &, Philosophe &> s_pairPhilo;

  Philosophe(s_pairBag&, s_pairPhilo&, int);
  ~Philosophe();

  void          operator()(Philosophe &);
  e_state       getState();

  static void   trampoline(Philosophe &);

private:

  void          sleep();
  void          eat();
  void          think();


  std::mutex    &_baguetteG;
  std::mutex    &_baguetteD;

  Philosophe    &_philoG;
  Philosophe    &_philoD;

  e_state       _state;
  const int     _id;
};

#endif //PHILOSOPHE_HPP

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

#include <mutex>
#include <iostream>
#include <curses.h>
#include <term.h>

class Display {
public:
    Display();
    ~Display();

    void print(int, std::string&);

private:
    std::mutex  _mtx;
};


#endif // DISPLAY_HPP

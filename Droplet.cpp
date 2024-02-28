#include "Droplet.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


Droplet::Droplet(int initialX) : x(initialX), y(0) {}
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 24;
void Droplet::fall() {
    y++;
}

void Droplet::display() {
  
    std::cout << "\033[" << y << ";" << x << "H";
 
    std::cout << "*";
}

bool Droplet::isAtBottom() {
    return y >= SCREEN_HEIGHT;
}

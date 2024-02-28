#include "Droplet.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Droplet::Droplet(int initialX) : x(initialX), y(0) {}
const int SCREEN_HEIGHT = 24;

void Droplet::fall() {
    y++;
}

void Droplet::display() {
    std::vector<char> symbols = { 1,$,%,3,@ };
    for (int i = 0; i < y; ++i) {
        std::cout << " ";
    }
    std::cout << "*"; 
}

bool Droplet::isAtBottom() {
    return y >= SCREEN_HEIGHT;
}

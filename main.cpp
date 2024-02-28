#include <iostream>
#include "Droplet.h" 

int main() {
   
    Droplet droplet(40);
    const int SCREEN_WIDTH = 80;
    const int SCREEN_HEIGHT = 24;
    
    while (true) {
        
        std::cout << "\033[2J\033[1;1H";

       
        droplet.fall();
        droplet.display();

       
        if (droplet.isAtBottom()) {
            droplet = Droplet(rand() % SCREEN_WIDTH + 1);
        }

        std::cout.flush();
        usleep(100000); 

    return 0;
}

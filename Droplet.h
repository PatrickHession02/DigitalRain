#ifndef MATRIXDROPLET_H
#define MATRIXDROPLET_H

class Droplet {
private:
    int x, y;
public:
    Droplet(int initialX);
    void fall();
    void display();
    bool isAtBottom();
};

#endif 

#ifndef MATRIXDROPLET_H
#define MATRIXDROPLET_H
#include <vector>
class Droplet {
private:
    int x, y;
    std::vector<int> chars = { 8,4,5,9 };
public:
    Droplet(int initialX);
    void fall();
    void display();
    bool isAtBottom();
};

#endif 

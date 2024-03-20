
/*
 _ __                       _    ,
' )  )    _/_          /   ' )  /
 /--'__.  /  __  o _. /_    /--/ _  _   _   o __ ____
/   (_/|_<__/ (_<_(__/ <_  /  (_</_/_)_/_)_<_(_)/ / <_
*/
#include "matrix_fall.h"

MatrixFall::MatrixFall() {
    xPosition = 0;
}

MatrixFall::MatrixFall(int x) {
    xPosition = x;
}

MatrixFall::MatrixFall(const MatrixFall& other) {
    xPosition = other.xPosition;
    Rain = other.Rain;
}

MatrixFall::~MatrixFall() {}

MatrixFall& MatrixFall::operator=(const MatrixFall& other) {
    if (this != &other) {
        xPosition = other.xPosition;
        Rain = other.Rain;
    }
    return *this;
}

MatrixFall::MatrixFall(int x, std::vector<std::string> rain) {
    xPosition = x;
    Rain = rain;
}

int MatrixFall::getXposition() const {
    return xPosition;
}

void MatrixFall::setRain(std::vector<std::string> rain) {
    Rain = rain;
}

std::vector<std::string> MatrixFall::getRain() const {
    return Rain;
}

void MatrixFall::setXposition(int x) {
    xPosition = x;
}

void MatrixFall::start() {
    while (true) {
        raining();

    }
}

void MatrixFall::raining() {
    // Clear the console screen
    system("cls"); // This works on Windows, you may need to use different commands on other operating systems

    
    std::string newDrop;
    for (int i = 0; i < 10; ++i) {
        if (rand() % 100 < 20)  
            newDrop += (char)(rand() % 94 + 33); // ASCII characters from '!' to '~'
        else
            newDrop += ' ';
    }
    if (Rain.size() >= 20) // Limit the number of raindrops
        Rain.erase(Rain.begin());
    Rain.push_back(newDrop);

    // Print the raindrops
    goToXY(xPosition, 0);
    for (const auto& drop : Rain)
        std::cout << drop << std::endl;
}

void MatrixFall::goToXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


std::ostream& operator<<(std::ostream& output, const MatrixFall& m) {
    for (const auto& drop : m.getRain())
        output << drop << std::endl;
    return output;
}

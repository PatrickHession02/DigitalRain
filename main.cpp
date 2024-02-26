#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <thread>
#include <windows.h>  

const int flipsPerLine = 5;
const int sleepTime = 100;

// Character set for the rain
const std::string characters = "1234567890qwertyuiopasdfghjklzxcvbnm,./';[]!@#$%^&*()-=_+";

// Function to get the width of the console window
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int main() {

    int width = getConsoleWidth();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, characters.size() - 1);

    std::vector<bool> switches(width, false);  

    
    system("Color 0A");  

    while (true) {
        for (int i = 0; i < width; ++i) {
            std::cout << (switches[i] ? characters[dist(gen)] : ' ');
        }
        std::cout << std::endl; 

      
        for (int i = 0; i < flipsPerLine; ++i) {
            switches[dist(gen)] = !switches[dist(gen)];
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
    }

    return 0;
}
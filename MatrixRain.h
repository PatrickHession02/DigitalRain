// MatrixRain.h
#ifndef MATRIXRAIN_H
#define MATRIXRAIN_H

#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h> // For Windows-specific console functions
#else
#include <sys/ioctl.h> // For Unix/Linux-specific console functions
#endif

class MatrixRain {
public:
    MatrixRain() : rows(0), columns(0), running(true) {} // Initialize rows and columns to 0
    ~MatrixRain() {
        running = false;
        if (rainThread.joinable())
            rainThread.join();
    }
    void start();
    void stop();
private:
    int rows;
    int columns;
    std::vector<std::vector<char>> matrix;
    std::thread rainThread;
    volatile bool running;

    void initializeMatrix();
    void draw();
    void rainDrops();
};

#endif // MATRIXRAIN_H

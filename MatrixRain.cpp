#include "matrix_fall.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <windows.h>

namespace MatrixFall {

    std::mutex mtx;
    const int MATRIX_WIDTH = 80;
    const int MATRIX_HEIGHT = 25;
    const int NUM_DROPS = 50;
    const int ANIMATION_SPEED_MS = 100;

    // Function to get a random character
    char getRandomChar() {
        return static_cast<char>('!' + rand() % 94);
    }

    // Function to simulate raindrop animation
    void simulateRaindrop(int raindropColumn) {
        try {
            std::vector<std::vector<char>> matrix(MATRIX_HEIGHT, std::vector<char>(MATRIX_WIDTH, ' '));

            int raindropLength = 5 + rand() % 10;

            for (int row = 0; row < raindropLength; ++row) {
                int currentRow = row;
                while (currentRow >= 0 && currentRow < MATRIX_HEIGHT) {
                    matrix[currentRow][raindropColumn] = getRandomChar();
                    ++currentRow;
                }

                printMatrixWithRaindrop(matrix);

                currentRow = row;
                while (currentRow >= 0 && currentRow < MATRIX_HEIGHT) {
                    matrix[currentRow][raindropColumn] = ' ';
                    ++currentRow;
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(ANIMATION_SPEED_MS));
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Exception occurred during raindrop simulation: " << e.what() << std::endl;
        }
    }

    // Function to print the matrix with raindrops
    void printMatrixWithRaindrop(const std::vector<std::vector<char>>& matrix) {
        try {
            for (const auto& row : matrix) {
                std::lock_guard<std::mutex> guard(mtx);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                for (char pixel : row) {
                    std::cout << pixel;
                }
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Exception occurred while printing matrix: " << e.what() << std::endl;
        }
    }

    // Function to simulate raindrops using threads
    void simulateRaindrops() {
        std::thread raindrops[NUM_DROPS];

        for (int i = 0; i < NUM_DROPS; ++i) {
            int raindropColumn = rand() % MATRIX_WIDTH;
            raindrops[i] = std::thread(simulateRaindrop, raindropColumn);
        }

        for (int i = 0; i < NUM_DROPS; ++i) {
            raindrops[i].join();
        }
    }

    // Function to call all functions in the namespace
    void runAllFunctions() {
        char randomChar = getRandomChar();
        std::vector<std::vector<char>> matrix(MATRIX_HEIGHT, std::vector<char>(MATRIX_WIDTH, 'X'));
        printMatrixWithRaindrop(matrix);
        simulateRaindrops();
    }

} // namespace MatrixFall

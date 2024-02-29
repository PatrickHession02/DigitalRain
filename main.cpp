// main.cpp
#include "MatrixRain.h"

int main() {
    MatrixRain matrixRain; // Create MatrixRain object without specifying rows and columns

    matrixRain.start();

    std::cout << "Press any key to stop the Matrix Rain..." << std::endl;
    std::cin.get(); // Wait for user input

    matrixRain.stop();

    return 0;
}

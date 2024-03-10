#include "MatrixRain.h"

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Define the width and height of the matrix
    const int width = 80; // Adjust the width as needed
    const int height = 25; // Adjust the height as needed

    while (true) {
        printMatrix(width, height);

        // Sleep for a short period
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Clear the screen
        std::system("cls"); // For UNIX-like systems
        // std::system("cls"); // For Windows systems
    }

    return 0;
}

#include "MatrixRain.h"
#include <iostream>
#include <thread>
#include <vector>
#include <random>

char getRandomChar() {
    static const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    static const int max_index = sizeof(charset) - 1;
    return charset[rand() % max_index];
}

void printDrop(int width, int height, const std::string& green_color, const std::string& reset_color) {
    // Generate a random starting position for the drop
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, width - 1);
    int x = dis(gen);

    // Generate a random speed for the drop
    std::uniform_int_distribution<int> speed_dis(50, 150);
    int speed = speed_dis(gen);

    // Generate a random length for the drop
    std::uniform_int_distribution<int> length_dis(5, height); // Adjust as needed
    int length = length_dis(gen);

    // Print the drop's animation
    for (int frame = 0; frame < length + 5; ++frame) {
        // Only print the drop if it's within the visible area of the screen
        if (frame >= 0 && frame < length && x >= 0 && x < width) {
            // Move the cursor to the starting position
            std::cout << "\033[" << frame << ";" << x + 1 << "H";

            // Print the drop
            std::cout << green_color << getRandomChar() << reset_color << std::flush;
        }

        // Sleep for the specified speed
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));

        // Clear the character at the current position
        if (frame >= 0 && frame < length && x >= 0 && x < width) {
            std::cout << "\033[" << frame << ";" << x + 1 << "H" << green_color << " " << reset_color; // Clear character
        }
    }
}

void printMatrix(int width, int height) {
    // ANSI escape code for green text
    const std::string green_color = "\033[32m";
    // ANSI escape code to reset text color
   

    // Number of drops
    const int num_drops = 10; // Adjust as needed

    // Vector to store threads
    std::vector<std::thread> threads;

    // Start threads for each drop
    for (int i = 0; i < num_drops; ++i) {
        // Emplace new threads to the vector
        threads.emplace_back(printDrop, width, height, std::ref(green_color));
        // Sleep for a random duration before starting the next thread
        std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 500));
    }

    // Join threads
    for (auto& thread : threads) {
        thread.join();
    }

    // Move the cursor to the last position to avoid scrolling
    std::cout << "\033[" << height << ";0H";
}

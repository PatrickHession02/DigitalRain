// MatrixRain.cpp
#include "MatrixRain.h"

#ifdef _WIN32
int getWindowWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int getWindowHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
#else
int getWindowWidth() {
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return size.ws_col;
}

int getWindowHeight() {
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return size.ws_row;
}
#endif

void MatrixRain::start() {
    initializeMatrix();
    rainThread = std::thread(&MatrixRain::rainDrops, this);
}

void MatrixRain::stop() {
    running = false;
    if (rainThread.joinable())
        rainThread.join();
}

void MatrixRain::initializeMatrix() {
    rows = getWindowHeight();
    columns = getWindowWidth();
    matrix.resize(rows, std::vector<char>(columns, ' '));
}

void MatrixRain::draw() {
    // Move cursor to the top-left corner
    std::cout << "\033[H";
    std::cout << "\033[2J";

    // Set color to green
    std::cout << "\033[32m";

    // Draw matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }

    // Reset color
    std::cout << "\033[0m";
}
void MatrixRain::rainDrops() {
    while (running) {
        for (int j = 0; j < columns; ++j) {
            if (rand() % 20 == 1) {
                int length = rand() % 10 + 3; // Randomize length of raindrop
                int start = rand() % (rows - length); // Random starting position
                for (int k = start; k < start + length; ++k) {
                    matrix[k][j] = rand() % 94 + 33; // ASCII characters from '!' to '~'
                }
            }
            else {
                for (int i = 0; i < rows; ++i) {
                    if (matrix[i][j] != ' ') {
                        matrix[i][j] = ' ';
                        if (i + 1 < rows) {
                            matrix[i + 1][j] = rand() % 94 + 33;
                        }
                    }
                }
            }
        }

        draw(); // Redraw after updating each column
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Adjust speed
    }
}

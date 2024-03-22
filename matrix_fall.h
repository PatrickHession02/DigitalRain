#ifndef MATRIX_FALL_H
#define MATRIX_FALL_H
#include <vector>
#include <mutex>

namespace MatrixFall {

    extern const int MATRIX_WIDTH;
    extern const int MATRIX_HEIGHT;
    extern const int NUM_DROPS;
    extern const int ANIMATION_SPEED_MS;

    char getRandomChar();
    void printMatrixWithRaindrop(const std::vector<std::vector<char>>& matrix);
    void simulateRaindrop(int raindropColumn);
    void runAllFunctions();
} // namespace MatrixFall

#endif // MATRIX_FALL_H

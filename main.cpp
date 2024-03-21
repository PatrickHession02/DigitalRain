/*
 _ __                       _    ,
' )  )    _/_          /   ' )  /
 /--'__.  /  __  o _. /_    /--/ _  _   _   o __ ____
/   (_/|_<__/ (_<_(__/ <_  /  (_</_/_)_/_)_<_(_)/ / <_
*/
#include "matrix_fall.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include "MatrixRainTest.h"
const int MATRIX_WIDTH = 80;
const int MATRIX_HEIGHT = 25;
const int NUM_DROPS = 50; // Number of raindrops
const int ANIMATION_SPEED_MS = 100; // Animation speed in milliseconds

int main() {
    srand(time(nullptr));
    MatrixRainTest::testGetRandomChar();
    MatrixRainTest::testPrintMatrixWithRaindrop();
    MatrixRainTest::testSimulateRaindrop();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::thread raindrops[NUM_DROPS];

    for (int i = 0; i < NUM_DROPS; ++i) {
        int raindropColumn = rand() % MATRIX_WIDTH;
        raindrops[i] = std::thread(MatrixFall::simulateRaindrop, raindropColumn);
    }

    for (int i = 0; i < NUM_DROPS; ++i) {
        raindrops[i].join();
    }

    return 0;
}
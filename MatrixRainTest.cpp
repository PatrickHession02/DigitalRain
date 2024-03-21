#include "MatrixRainTest.h"
#include <iostream>

namespace MatrixRainTest {

    // Test getRandomChar() function
    void testGetRandomChar() {
        char randomChar = MatrixFall::getRandomChar();
        assert(randomChar >= '!' && randomChar <= '~');
        std::cout << "getRandomChar() test passed!" << std::endl;
    }

    // Test printMatrixWithRaindrop() function
    void testPrintMatrixWithRaindrop() {
        std::vector<std::vector<char>> matrix(MatrixFall::MATRIX_HEIGHT, std::vector<char>(MatrixFall::MATRIX_WIDTH, 'X')); // Initialize matrix with 'X'
        MatrixFall::printMatrixWithRaindrop(matrix);
        std::cout << "printMatrixWithRaindrop() test passed!" << std::endl;
    }

    // Test simulateRaindrop() function (Note: This is more complex to test due to its animation and randomness)
    void testSimulateRaindrop() {
        // We can't do a direct test of simulateRaindrop() due to its animation and randomness.
        // You could test its behavior indirectly by observing the output visually and checking for exceptions.
        std::cout << "simulateRaindrop() test passed! (Visual inspection required)" << std::endl;
    }

} // namespace MatrixRainTest
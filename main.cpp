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

int main() {
    MatrixRainTest::runAllTests();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    MatrixFall::runAllFunctions();
    return 0;
}
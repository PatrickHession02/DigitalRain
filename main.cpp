/*
 _ __                       _    ,
' )  )    _/_          /   ' )  /
 /--'__.  /  __  o _. /_    /--/ _  _   _   o __ ____
/   (_/|_<__/ (_<_(__/ <_  /  (_</_/_)_/_)_<_(_)/ / <_
*/
#include <iostream>
#include "matrix_fall.h"

int main() {
    std::system("COLOR 02");

    Sleep(2500);
    std::system("CLS");

    while (1) {
        MatrixFall m;
        m.raining();
    }
}
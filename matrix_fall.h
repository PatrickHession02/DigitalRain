/*
 _ __                       _    ,
' )  )    _/_          /   ' )  /
 /--'__.  /  __  o _. /_    /--/ _  _   _   o __ ____
/   (_/|_<__/ (_<_(__/ <_  /  (_</_/_)_/_)_<_(_)/ / <_
*/
#ifndef MATRIX_FALL_H
#define MATRIX_FALL_H

#include <iostream>
#include <Windows.h>
#include <vector>

class MatrixFall {
public:
    MatrixFall();
    MatrixFall(int);
    MatrixFall(const MatrixFall&);
    ~MatrixFall();
    MatrixFall& operator=(const MatrixFall&);
    MatrixFall(int, std::vector<std::string>);

    int getXposition()const;
    void setRain(std::vector<std::string>);
    std::vector<std::string> getRain()const;
    void setXposition(int);

    void start();
    void raining();
    void goToXY(int, int);
    
private:
    int xPosition;
    std::vector<std::string>Rain;
};
std::ostream& operator<<(std::ostream& output, const MatrixFall& m);
#endif 
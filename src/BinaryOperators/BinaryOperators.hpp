#include <bitset>
#include <iostream>
#include <string>
#include <vector>

#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

const int BIT_SIZE = 32;

class BinaryOperators{
    std::string bits = "";

    public:
        BinaryOperators();
        BinaryOperators(std::string);
        void rotate(int);
        void shift(int);
        BinaryOperators operator+(BinaryOperators);
        BinaryOperators operator^(BinaryOperators);
        BinaryOperators choice(BinaryOperators, BinaryOperators);
        BinaryOperators major(BinaryOperators, BinaryOperators);
        BinaryOperators halfRotationZero();
        BinaryOperators halfRotationOne();
        BinaryOperators fullRotationZero();
        BinaryOperators fullRotationOne();
        std::string toString();

};

#endif

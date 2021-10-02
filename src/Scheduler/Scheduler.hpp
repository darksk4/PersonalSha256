#include <BinaryOperators.hpp>
#include <vector>
#include <string>


#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler
{
    std::vector<BinaryOperators> schedule; 
    BinaryOperators xorFunction(BinaryOperators, BinaryOperators);
    void generate64();

    public:
        Scheduler(std::string);
        BinaryOperators operator[] (unsigned int);
};

#endif

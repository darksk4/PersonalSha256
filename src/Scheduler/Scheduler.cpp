#include "Scheduler.hpp"
#include <iostream>
#include <cstring>

/*
 Class BinaryOperators
    Major
    Choice
 class Blocked
    Where there are multiple of compression
 Class Scheduler
 Class Compression : Scheduler

 *
 */

Scheduler::Scheduler(std::string words)
{
    std::string temp = words;
    schedule = [&temp]()
    {
        std::vector<BinaryOperators> answer;
        while(!temp.empty())
        {
            answer.emplace_back(temp.substr(0, 32));
            temp.erase(0, 32);
        }
        return answer;
    }();
    generate64();
}

void Scheduler::generate64()
{
    if (schedule.size() != 16)
        return;

    for (int counter = schedule.size() ; counter < 64 ; counter++)
    {
        BinaryOperators answer =
            schedule[counter - 2].halfRotationOne() +
            schedule[counter - 7] +
            schedule[counter - 15].halfRotationZero() +
            schedule[counter - 16];
        schedule.push_back(answer);
    }
}


BinaryOperators Scheduler::operator[](unsigned int index)
{
    return schedule[index];
}


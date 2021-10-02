#include <Scheduler.hpp>
#include <gtest/gtest.h>

class SchedulerTest : public testing::Test
{
    void SetUp(){}
    void TearDown()
    {
        delete schedule;
    } 
    protected:
        Scheduler* schedule = new Scheduler("0000000000000000001111111111111");
};


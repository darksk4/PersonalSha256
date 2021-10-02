#include <BinaryOperators.hpp>
#include <gtest/gtest.h>

class BinaryOperatorsTest : public testing::Test
{
    void SetUp(){}
    void TearDown(){}

};


TEST_F(BinaryOperatorsTest, TestConstructor)
{
    const std::string input =  "011000010110001001100011";
    const std::string answer = "011000010110001001100011";

    BinaryOperators bit = BinaryOperators(input.c_str());

    ASSERT_EQ(bit.toString(), answer);
}

TEST_F(BinaryOperatorsTest, TestShift)
{
    const std::string input =  "011000010110001001100011";
    const std::string answer = "001100001011000100110001";

    BinaryOperators bit = BinaryOperators(input.c_str());
    bit.shift(1);

    ASSERT_EQ(bit.toString(), answer);
}

TEST_F(BinaryOperatorsTest, TestRotate)
{
    const std::string input =  "011000010110001001100011";
    const std::string answer = "101100001011000100110001";

    BinaryOperators bit = BinaryOperators(input.c_str());
    bit.rotate(1);

    ASSERT_EQ(bit.toString(), answer);
}

TEST_F(BinaryOperatorsTest, TestRotateCase2)
{
    const std::string answer = "101100001011000100110001";
    const std::string input = "011000010110001001100011";

    BinaryOperators bit = BinaryOperators(input.c_str());
    bit.rotate(1);

    ASSERT_EQ(bit.toString(), answer);
}

TEST_F(BinaryOperatorsTest, TestAddCase)
{
    const std::string input =  "01100011";
    const std::string input2 = "10010101";
    const std::string answer = "11111000";

    BinaryOperators bit = BinaryOperators(input.c_str());
    BinaryOperators bit2 = BinaryOperators(input2.c_str());
    BinaryOperators bitAnswer = bit + bit2;

    ASSERT_EQ(bitAnswer.toString(), answer);
}

TEST_F(BinaryOperatorsTest, TestMajorCase)
{
    const std::string input =  "01100011";
    const std::string input2 = "10010101";
    const std::string input3 = "10110101";
    const std::string answer = "10110101";

    BinaryOperators bit = BinaryOperators(input.c_str());
    BinaryOperators bit2 = BinaryOperators(input2.c_str());
    BinaryOperators bit3 = BinaryOperators(input3.c_str());
    BinaryOperators bitAnswer = bit.major(bit2, bit3);

    ASSERT_EQ(bitAnswer.toString(), answer);
}

TEST_F(BinaryOperatorsTest, TestChoiceCase)
{ 
    const std::string input =  "01100001";
    const std::string input2 = "10010111";
    const std::string input3 = "10110101";
    const std::string answer = "10110111";

    BinaryOperators bit = BinaryOperators(input.c_str());
    BinaryOperators bit2 = BinaryOperators(input2.c_str());
    BinaryOperators bit3 = BinaryOperators(input3.c_str());
    BinaryOperators bitAnswer = bit.choice(bit2, bit3);

    ASSERT_EQ(bitAnswer.toString(), answer);
}

TEST_F(BinaryOperatorsTest, BinaryOperatorsHalfRotationZeroTest)
{
    const std::string input =  "00000000000000000011111111111111";
    const std::string answer = "11110001111111111100011110000000";
    
    ASSERT_EQ(BinaryOperators(input).halfRotationZero().toString(), answer);
}

TEST_F(BinaryOperatorsTest, BinaryOperatorsHalfRotationOneTest)
{
    const std::string input =  "00000000000000000011111111111111";
    const std::string answer = "00011000000000000110000000001111";

    ASSERT_EQ(BinaryOperators(input).halfRotationOne().toString(), answer);
}

TEST_F(BinaryOperatorsTest, BinaryOperatorsFullRotationZeroTest)
{
    const std::string input =  "00000000000000000011111111111111";
    const std::string answer = "00111111000001111111001111111110";

    ASSERT_EQ(BinaryOperators(input).fullRotationZero().toString(), answer);
}

TEST_F(BinaryOperatorsTest, BinaryOperatorsFullRotationOneTest)
{
    const std::string input =  "00000000000000000011111111111111";
    const std::string answer = "00000011111111111111111101111000";

    ASSERT_EQ(BinaryOperators(input).fullRotationOne().toString(), answer);
}

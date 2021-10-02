#include "BinaryOperators.hpp"

BinaryOperators::BinaryOperators()
{
}

BinaryOperators::BinaryOperators(std::string words) : bits(words){}

void BinaryOperators::rotate(int number)
{
    while (number--)
    {
        char temp = bits[bits.length() -1];
        bits.erase(bits.length() - 1, 1);
        bits = temp + bits;
    }

}

void BinaryOperators::shift(int number)
{
    while (number--)
    {
        bits.erase(bits.length() - 1, 1);
        bits = '0' + bits;
    }
} 

BinaryOperators BinaryOperators::operator+(BinaryOperators b)
{
    BinaryOperators answer;

    char carry = '0';
    for (int counter = b.bits.size() - 1 ;
        counter >= 0 ; counter--)
    {
        char current = '0';
        if (b.bits[counter] == '1' &&
            this->bits[counter] == '1')
        {
            current = '0';
            if (carry == '1')
                current = '1';

            carry = '1';
        }
        else if (b.bits[counter] == '1' ||
            this->bits[counter] == '1')
        {
            current = '1';
            if (carry == '1')
            {
                current = '0';
            }
        }
        else
        {
            current = '0';
            if (carry == '1')
            {
                current = '1';
                carry = '0';
            }
        }
        answer.bits = current + answer.bits;
    } 
    return answer;
}

BinaryOperators BinaryOperators::operator^(BinaryOperators b)
{
    BinaryOperators answer;
    
    for (int counter = 0 ; counter < b.bits.size() ; counter++)
    {
        if (b.bits[counter] == '0' && this->bits[counter] == '0')
            answer.bits += "0";
        else if (b.bits[counter] == '1' && this->bits[counter] == '1')
            answer.bits += "0";
        else
            answer.bits += "1";
    } 
    return answer;
} 

BinaryOperators BinaryOperators::choice(BinaryOperators a, BinaryOperators b)
{
    BinaryOperators answer;
    for (int counter = 0 ; counter < this->bits.size() ; counter++)
    {
        if (this->bits[counter] == '0')
            answer.bits += a.bits[counter];
        else
            answer.bits += b.bits[counter];
    } 
    return answer;
}

BinaryOperators BinaryOperators::major(BinaryOperators a, BinaryOperators b)
{
    BinaryOperators answer;
    for (int counter = 0 ; counter < this->bits.size() ; counter++)
    {

        int zero = 0;

        if (this->bits[counter] == '0')
            zero++;
        if (a.bits[counter] == '0')
            zero++;
        if (b.bits[counter] == '0') 
            zero++;

        if (zero >= 2)
            answer.bits += "0";
        else
            answer.bits += "1";
    } 
    return answer;
}

BinaryOperators BinaryOperators::halfRotationZero()
{
    BinaryOperators rotation7 = BinaryOperators(bits);
    BinaryOperators rotation18 = BinaryOperators(bits);
    BinaryOperators shift3 = BinaryOperators(bits);

    rotation7.rotate(7);
    rotation18.rotate(18);
    shift3.shift(3);

    return rotation7^rotation18^shift3;
}

BinaryOperators BinaryOperators::halfRotationOne()
{
    BinaryOperators rotation17 = BinaryOperators(bits);
    BinaryOperators rotation19 = BinaryOperators(bits);
    BinaryOperators shift10 = BinaryOperators(bits);

    rotation17.rotate(17);
    rotation19.rotate(19);
    shift10.shift(10);

    return rotation17^rotation19^shift10;
}

BinaryOperators BinaryOperators::fullRotationZero()
{
    BinaryOperators rotation2 = BinaryOperators(bits);
    BinaryOperators rotation13 = BinaryOperators(bits);
    BinaryOperators rotation22 = BinaryOperators(bits);

    rotation2.rotate(2);
    rotation13.rotate(13);
    rotation22.rotate(22);

    return rotation2^rotation13^rotation22;
}

BinaryOperators BinaryOperators::fullRotationOne()
{
    BinaryOperators rotation6 = BinaryOperators(bits);
    BinaryOperators rotation11 = BinaryOperators(bits);
    BinaryOperators rotation25 = BinaryOperators(bits);

    rotation6.rotate(6);
    rotation11.rotate(11);
    rotation25.rotate(25);

    return rotation6^rotation11^rotation25;
}


std::string BinaryOperators::toString()
{ 
    return bits;
}

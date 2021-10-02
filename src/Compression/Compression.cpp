#include "Compression.hpp"
#include <sstream>

Compression::Compression(std::vector<std::string> words)
{
    schedulers = [words]()
    {
        std::vector<Scheduler> answer;
        for (auto& item : words)
        {
            answer.emplace_back(item); 
        } 
        return answer; 
    }(); 

    h0 = initialValue[0];
    h1 = initialValue[1];
    h2 = initialValue[2];
    h3 = initialValue[3];
    h4 = initialValue[4];
    h5 = initialValue[5];
    h6 = initialValue[6];
    h7 = initialValue[7];

    cycle();
}

void Compression::cycle()
{

    for (auto& item : schedulers )
    {
        BinaryOperators a = h0;
        BinaryOperators b = h1;
        BinaryOperators c = h2;
        BinaryOperators d = h3;
        BinaryOperators e = h4;
        BinaryOperators f = h5;
        BinaryOperators g = h6;
        BinaryOperators h = h7;


        std::cout << "INITIAL : " << std::endl;
        std::cout << "h0 : " << h0.toString() << std::endl;
        std::cout << "h1 : " << h1.toString() << std::endl;
        std::cout << "h2 : " << h2.toString() << std::endl;
        std::cout << "h3 : " << h3.toString() << std::endl;
        std::cout << "h4 : " << h4.toString() << std::endl;
        std::cout << "h5 : " << h5.toString() << std::endl;
        std::cout << "h6 : " << h6.toString() << std::endl;
        std::cout << "h7 : " << h7.toString() << std::endl;

        for (int counter = 0 ; counter < 64; counter++)
        {
            std::cout << item[counter].toString() << std::endl;
            BinaryOperators T1 = e.fullRotationOne() + e.choice(g, f) + h + constants[counter] + item[counter];
            BinaryOperators T2 = a.fullRotationZero() + a.major(b, c);

            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        std::cout << "add value : " << std::endl;
        std::cout << "h0 : " << h0.toString() << std::endl;
        std::cout << "h1 : " << h1.toString() << std::endl;
        std::cout << "h2 : " << h2.toString() << std::endl;
        std::cout << "h3 : " << h3.toString() << std::endl;
        std::cout << "h4 : " << h4.toString() << std::endl;
        std::cout << "h5 : " << h5.toString() << std::endl;
        std::cout << "h6 : " << h6.toString() << std::endl;
        std::cout << "h7 : " << h7.toString() << std::endl;
        h0 = h0 + a;
        h1 = h1 + b;
        h2 = h2 + c;
        h3 = h3 + d;
        h4 = h4 + e;
        h5 = h5 + f;
        h6 = h6 + g;
        h7 = h7 + h;

        std::cout << "END value : " << std::endl;
        std::cout << "h0 : " << h0.toString() << std::endl;
        std::cout << "h1 : " << h1.toString() << std::endl;
        std::cout << "h2 : " << h2.toString() << std::endl;
        std::cout << "h3 : " << h3.toString() << std::endl;
        std::cout << "h4 : " << h4.toString() << std::endl;
        std::cout << "h5 : " << h5.toString() << std::endl;
        std::cout << "h6 : " << h6.toString() << std::endl;
        std::cout << "h7 : " << h7.toString() << std::endl;
    }
}

std::string Compression::binaryToHex(std::string words)
{
    std::bitset<4> binary(words);
    std::stringstream ss;
    ss << std::hex << binary.to_ulong();

    return ss.str();
}

std::string Compression::toString()
{
    std::string temp = h0.toString() + h1.toString() +
           h2.toString() + h3.toString() +
           h4.toString() + h5.toString() +
           h6.toString() + h7.toString();
    std::string answer;

    while (!temp.empty())
    {
        answer += binaryToHex(temp.substr(0, 4));
        temp.erase(0 , 4);
    }

    return answer;
}

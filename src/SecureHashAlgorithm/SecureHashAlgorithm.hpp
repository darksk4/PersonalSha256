#include <Compression.hpp>
#include <iostream>


#ifndef SECUREHASHALGORITHM_H
#define SECUREHASHALGORITHM_H

class SecureHashAlgorithm
{
    Compression* compression;
    public :
        SecureHashAlgorithm(std::string);
        std::string toString();

};

#endif

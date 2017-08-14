#include "token.h"
#include <iostream>

void Token::printType(void)
{
    if (isIdentifier())
        std::cout << "is Identifier:\t" << getIdName() << std::endl;
    else if (isNumber())
        std::cout << "is Number:\t" << getNumber() << std::endl;
    else if (isString())
        std::cout << "is String:\t" << getStrText() << std::endl;
}
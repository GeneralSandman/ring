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
    else if (m_nLine == -1)
        std::cout << "is Eol:\t" << std::endl;
}

bool Token::isNotEof(void)
{
    return (m_nLine!=-1);
}

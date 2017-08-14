#ifndef TOKEN_H
#define TOKEN_H
#include<cstddef>
#include<climits>
#include<iostream>
class Token
{
  private:
    size_t m_nLine;

  public:
    Token(size_t l):m_nLine(l){}
    size_t getLineNu(void){return m_nLine;}

    bool isIdentifier(void){return false;}
    bool isNumber(void){return false;}
    bool isString(void){return false;}

    int getNumber(void){return INT_MIN;}
    std::string getText(void){return "";}

};

#endif
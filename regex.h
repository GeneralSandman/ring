#ifndef REGEX_H
#define REGEX_H
#include <iostream>

class Regex
{
  private:
    std::string m_nPattern;

  public:
    Regex(const std::string &pattern)
        : m_nPattern(pattern) {}

    void regex_match(const std::string &);

    bool hasIdentifier();
    bool hasNumber();
    bool hasString();

    std::string getIdentifier();
    int getNumber();
    std::string getString();

    ~Regex();
};

#endif // !REGEX_H

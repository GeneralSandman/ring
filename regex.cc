#include <boost/regex.hpp>
#include "regex.h"
#include "token.h"
#include <iostream>

void Regex::setLineNu(int l)
{
    m_nLine = l;
}

bool Regex::m_fLookAt(const std::string &sou, int &begin, boost::regex reg, boost::cmatch &mat)
{
    bool r = regex_search(sou.c_str() + begin, mat, reg);

    if (r)
    {
        auto p = mat[0];
        int new_begin = p.first - sou.c_str();
        int end = p.second - sou.c_str();
        begin = end;
        return true;
    }
    return false;
}

void Regex::m_fFillQueue(boost::cmatch &matcher, std::queue<Token *> &result)
{
    std::string m = matcher[1];
    if (m != "")
    {
        if (matcher[2] == "")
        {
            Token *token;
            if (matcher[3] != "")
            {
                // std::cout << "is number:" << matcher[3] << std::endl;
                token = new NumToken(m_nLine, stoi(matcher[3]));
            }
            else if (matcher[4] != "")
            {
                // std::cout << "is string:" << matcher[4] << std::endl;
                token = new StrToken(m_nLine, matcher[4]);
            }
            else
            {
                // std::cout << "is identifier:" << matcher[1] << std::endl;
                token = new IdToken(m_nLine, matcher[1]);
            }
            result.push(token);
        }
    }
}

Regex::Regex(const std::string &pattern)
    : m_nPattern(pattern),
      m_nRegex(pattern)
{
}

void Regex::regex_match(int line,const std::string &source, std::queue<Token *> &res)
{
    m_nLine=line;
    int begin = 0;
    int end = source.size();
    boost::cmatch matcher;
    while (begin < end)
    {
        if (m_fLookAt(source, begin, m_nRegex, matcher))
            m_fFillQueue(matcher, res);
    }
}

Regex::~Regex()
{
}

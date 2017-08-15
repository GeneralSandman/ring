#include "lexer.h"
#include "reader.h"
#include "regex.h"
#include <memory>
#include <algorithm>
#include <iostream>

bool Lexer::m_fFillQueue(int i)
{
    while (i >= m_nQueue.size())
    {
        if (m_pReader->haveMore())
        {
            string cur = m_pReader->readLine();
            m_pRegex->regex_match(1, cur, m_nQueue);
        }
        else
            return false;
    }
    
    return true;
}

void Lexer::m_fParserNewLine()
{
}

void Lexer::addToken()
{
}

Lexer::Lexer(const std::string &pattern,
             const std::string &file)
{
    m_nPattern;

    m_pReader = std::make_shared<Reader>(Reader(file));
    m_pRegex = std::make_shared<Regex>(Regex(m_nPattern));
    //init m_nQueue
    m_nMore = true;
}

shared_ptr<Token> Lexer::read()
{
    if (m_fFillQueue(0))
    {
        shared_ptr<Token> res = m_nQueue.front();
        m_nQueue.pop_front();
        return res;
    }
    else
    {
        return Eol;
    }
}

shared_ptr<Token> Lexer::peek(int i)
{
    if (m_fFillQueue(i))
    {
        return m_nQueue[i];
    }
    else
    {
        return Eof;
    }
}

Lexer::~Lexer()
{
}

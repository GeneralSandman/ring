#include "lexer.h"
#include "token.h"
#include "reader.h"
#include "regex.h"
#include <memory>
#include <algorithm>
#include <iostream>

bool Lexer::m_fFillQueue(int i)
{
    while (i >= m_nQueue.size())
    {
        if (m_nMore)
            m_fParserNewLine();
        else
            return false;
    }
    return true;
}

void Lexer::m_fParserNewLine()
{
    if (m_pReader->haveMore())
    {
        m_nCurLineNu++;
        std::string cur = m_pReader->readLine();
        m_pRegex->regex_match(m_nCurLineNu, cur, m_nQueue);
    }
    else
        m_nMore = false;
}

Lexer::Lexer(const std::string &pattern,
             const std::string &file)
{
    m_nPattern = pattern;
    m_pReader = std::make_shared<Reader>(Reader(file));
    m_pRegex = std::make_shared<Regex>(Regex(m_nPattern));
    //init m_nQueue
    m_nCurLineNu = 0;
    m_nMore = true;
}

std::shared_ptr<Token> Lexer::read()
{
    std::shared_ptr<Token> result;
    if (m_fFillQueue(0))
    {
        result = m_nQueue.front();
        m_nQueue.pop_front();
    }
    else
    {
        result = std::shared_ptr<Token>(new EofToken());
    }
    return result;
}

std::shared_ptr<Token> Lexer::peek(int i)
{
    std::shared_ptr<Token> result;
    if (m_fFillQueue(i))
    {
        result = m_nQueue[i];
    }
    else
    {
        result = std::shared_ptr<Token>(new EofToken());
    }

    return result;
}

Lexer::~Lexer()
{
}

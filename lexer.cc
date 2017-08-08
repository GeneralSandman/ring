#include "lexer.h"
#include "rule.h"
#include <memory>
#include <algorithm>

class Reader;
using namespace std;
Lexer::Lexer(shared_ptr<Reader> read)
    : m_nReader(read),
      m_nRules(),
      m_nResult()
{
}

void Lexer::m_fRemoveComment()
{
}

void Lexer::AddRule(shared_ptr<Rule> rule)
{
    m_nRules[rule->getName()] = rule.get();
}

void Lexer::RemoveRule(shared_ptr<Rule> rule)
{
    auto p = find(m_nRules.begin(), m_nRules.end(), rule.get());
    if (p != m_nRules.end())
    {
        m_nRules.erase(p);
    }
}
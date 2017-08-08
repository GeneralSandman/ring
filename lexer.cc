#include "lexer.h"
#include "reader.h"
#include <memory>
using namespace std;
Lexer::Lexer() : m_nRules()
{
    m_nReader = shared_ptr<Reader>(new Reader());
}

void Lexer::m_fRemoveComment()
{
}

void Lexer::AddRule(Rule &rule)
{
}

void Lexer::RemoveRule(Rule &rule)
{
}
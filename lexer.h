#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <queue>
using namespace std;
class Rule;
class Reader;
typedef pair<string, string> Token;
class Lexer
{
private:
  shared_ptr<Reader> m_nReader;
  map<string, Rule *> m_nRules;
  queue<Token> m_nResult;

  void m_fRemoveComment();

public:
  Lexer(shared_ptr<Reader> read);
  void AddRule(shared_ptr<Rule>);
  void RemoveRule(shared_ptr<Rule>);
  ~Lexer();
};

#endif
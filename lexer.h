#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <string>
#include <map>
#include <memory>

using namespace std;
class Rule;
class Reader;

class Lexer
{
private:
  shared_ptr<Reader> m_nReader;
  map<string, Rule *> m_nRules;
  void m_fRemoveComment();

public:
  Lexer();
  void AddRule(Rule &);
  void RemoveRule(Rule &);
  ~Lexer();
};

#endif
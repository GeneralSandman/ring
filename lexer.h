#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <queue>
using namespace std;
class Token;
class Reader;
class Regex;
class Lexer
{
private:
  static std::string m_nPattern;

  shared_ptr<Reader> m_pReader;
  shared_ptr<Regex> m_pRegex;
  std::deque<shared_ptr<Token>> m_nQueue;
  bool m_nMore;

  bool m_fFillQueue(int i);
  void m_fParserNewLine();
  void addToken();

public:
  Lexer(const std::string &, const std::string &);
  shared_ptr<Token> read();
  shared_ptr<Token> peek(int i);
  ~Lexer();
};

#endif
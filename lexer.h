#ifndef LEXER_H
#define LEXER_H
#include <memory>
#include <queue>
class Token;
class Reader;
class Regex;
class Lexer
{
private:
  std::string m_nPattern;

  std::shared_ptr<Reader> m_pReader;
  std::shared_ptr<Regex> m_pRegex;
  std::deque<std::shared_ptr<Token>> m_nQueue;
  int m_nCurLineNu;
  bool m_nMore;

  bool m_fFillQueue(int i);
  void m_fParserNewLine();

public:
  Lexer(const std::string &, const std::string &);
  std::shared_ptr<Token> read();
  std::shared_ptr<Token> peek(int i);
  ~Lexer();
};

#endif